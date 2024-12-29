#include <climits>
#include <iostream>
#include <queue>
#include <vector>

// Структура, представляющая ребро графа
struct Edge {
    int begin;     // Начальная вершина
    int end;       // Конечная вершина
    int flow;      // Текущий поток
    int capacity;  // Вместимость ребра
    bool used;     // Флаг, показывающий, использовано ли ребро

    // Конструктор, инициализирующий параметры ребра
    explicit Edge(int b, int e, int w) : begin(b), end(e), flow(0), capacity(w), used(false) {
    }

    // Метод, возвращающий остаточную пропускную способность ребра
    [[nodiscard]] int GetStream() const {
        return capacity - flow;
    }
};

// Структура, представляющая вершину графа
struct Vertex {
    std::vector<Edge> neighbours;  // Список смежных ребер
};

// Класс, представляющий граф
class Graph {
private:
    std::vector<Vertex> vertices_;  // Список вершин графа
    std::vector<int> distance_;     // Вектор расстояний от источника
    std::vector<int> parents_;      // Вектор предков для восстановления пути
    int s_;  // Источник
    int t_;  // Сток

public:
    friend std::istream &operator>>(std::istream &is, Graph &graph);
    int BFS(int vertex, int destination);  // Поиск в ширину
    int FindEdge(int begin_vertex, int end_vertex);  // Поиск ребра
    void Karp();  // Алгоритм Эдмондса-Карпа
};

// Перегрузка оператора ввода для графа
std::istream &operator>>(std::istream &is, Graph &graph) {
    int n = 0;  // Количество вершин
    int m = 0;  // Количество ребер
    is >> n >> m;
    graph.s_ = 0;  // Начальная вершина (источник)
    graph.t_ = n - 1;  // Конечная вершина (сток)
    graph.vertices_.resize(n);
    graph.parents_.resize(n, -1);
    graph.distance_.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int begin = 0;
        int end = 0;
        int weight = 0;
        is >> begin >> end >> weight;
        --begin;  // Приведение к нумерации с нуля
        --end;    // Приведение к нумерации с нуля
        graph.vertices_[begin].neighbours.emplace_back(begin, end, weight);  // Прямое ребро
        graph.vertices_[end].neighbours.emplace_back(end, begin, -weight);  // Обратное ребро
    }
    return is;
}

// Метод для поиска ребра между двумя вершинами
int Graph::FindEdge(int begin_vertex, int end_vertex) {
    for (int i = 0; i < static_cast<int>(vertices_[begin_vertex].neighbours.size()); i++) {
        if (vertices_[begin_vertex].neighbours[i].end == end_vertex) {
            return i;
        }
    }
    return 0;  // Если ребро не найдено, возвращаем 0 (по умолчанию)
}

// Метод для поиска в ширину (BFS) для нахождения пути в сети
int Graph::BFS(int vertex, int destination) {
    std::queue<int> queue;
    distance_[vertex] = 0;
    parents_[vertex] = vertex;
    queue.push(vertex);
    while (!queue.empty()) {
        int parent = queue.front();
        queue.pop();
        for (auto &edge : vertices_[parent].neighbours) {
            if (distance_[edge.end] == -1 && !edge.used) {  // Если вершина не посещена и ребро не использовано
                queue.push(edge.end);
                parents_[edge.end] = parent;
                distance_[edge.end] = distance_[parent] + 1;
            }
        }
    }
    return distance_[destination];  // Возвращаем расстояние до стока
}

// Алгоритм Эдмондса-Карпа для нахождения максимального потока
void Graph::Karp() {
    while (true) {
        int c_min = INT_MAX;
        std::fill(parents_.begin(), parents_.end(), -1);
        std::fill(distance_.begin(), distance_.end(), -1);
        if (BFS(s_, t_) != -1) {  // Если существует путь от источника до стока
            int current = t_;
            while (parents_[current] != current) {  // Проходим по найденному пути и находим минимальную остаточную пропускную способность
                int edge = FindEdge(parents_[current], current);
                c_min = std::min(c_min, vertices_[parents_[current]].neighbours[edge].GetStream());
                current = parents_[current];
            }
            current = t_;
            while (parents_[current] != current) {  // Обновляем потоки вдоль пути
                int edge = FindEdge(parents_[current], current);
                vertices_[parents_[current]].neighbours[edge].flow += c_min;
                int rev_edge = FindEdge(current, parents_[current]);
                vertices_[current].neighbours[rev_edge].flow -= c_min;
                if (vertices_[parents_[current]].neighbours[edge].GetStream() == 0) {
                    vertices_[parents_[current]].neighbours[edge].used = true;
                }
                current = parents_[current];
            }
        } else {
            break;  // Если пути не существует, выходим из цикла
        }
    }
    int sum = 0;
    for (auto &i : vertices_[s_].neighbours) {  // Суммируем потоки из источника
        sum += (i.flow > 0 ? i.flow : 0);
    }
    std::cout << sum << std::endl;  // Выводим максимальный поток
}

int main() {
    Graph graph;
    std::cin >> graph;  // Вводим граф
    graph.Karp();  // Запускаем алгоритм Эдмондса-Карпа
    return 0;
}
