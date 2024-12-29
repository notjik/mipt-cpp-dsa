#include <climits>
#include <iostream>
#include <set>
#include <vector>

// Класс, представляющий ребро в графе
class Edge {
public:
    int begin;    // Начальная вершина ребра
    int end;      // Конечная вершина ребра
    int weight;   // Вес (длина) ребра

    // Конструктор для инициализации ребра
    Edge(int src, int dest, int w) : begin(src), end(dest), weight(w) {
    }

    // Перегрузка оператора < для сравнения ребер по весу
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Класс, представляющий вершину в графе
class Vertex {
public:
    std::vector<Edge> neighbours;   // Список смежных ребер (соседей)
};

// Класс, представляющий весь граф
class Graph {
public:
    int Prim();   // Метод для выполнения алгоритма Прима
    friend std::istream& operator>>(std::istream& is, Graph& graph);  // Перегрузка оператора >> для ввода графа

private:
    std::vector<Vertex> vertices_;  // Вектор вершин графа
};

// Перегрузка оператора >> для чтения входных данных графа
std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0;
    int m = 0;
    is >> n >> m;   // Чтение числа вершин (n) и ребер (m)
    graph.vertices_.resize(n);   // Изменение размера вектора вершин

    // Чтение каждого ребра и добавление его в граф
    for (int i = 0; i < m; i++) {
        int begin = 0;
        int end = 0;
        int weight = 0;
        is >> begin >> end >> weight;   // Чтение начальной вершины, конечной вершины и веса ребра
        begin--;   // Приведение индексов к нумерации с нуля
        end--;     // Приведение индексов к нумерации с нуля

        // Создание обоих направлений ребра (так как граф неориентированный)
        Edge edge = Edge(begin, end, weight);
        Edge rev_edge = Edge(end, begin, weight);

        // Добавление ребер в списки смежности обеих вершин
        graph.vertices_[begin].neighbours.emplace_back(edge);
        graph.vertices_[end].neighbours.emplace_back(rev_edge);
    }
    return is;
}

// Метод для выполнения алгоритма Прима на графе
int Graph::Prim() {
    std::vector<int> dist(vertices_.size(), INT_MAX);   // Массив расстояний до вершин
    std::vector<bool> used(vertices_.size(), false);    // Массив посещенных вершин
    std::multiset<Edge> edges;   // Мультисет для хранения ребер, отсортированных по весу
    int r = 0;   // Начальная вершина (можно выбрать любую вершину в качестве начальной)
    dist[r] = 0;   // Расстояние до начальной вершины равно 0
    used[r] = true;   // Отмечаем начальную вершину как посещенную
    int sum = 0;   // Переменная для хранения общего веса минимального остовного дерева

    // Добавляем все ребра, инцидентные начальной вершине, в мультисет
    for (auto& i : vertices_[r].neighbours) {
        edges.insert(i);
    }

    // Основной цикл алгоритма Прима
    while (!edges.empty()) {
        Edge v = *edges.begin();   // Получаем ребро с минимальным весом
        edges.erase(edges.begin());   // Удаляем его из мультисета

        // Если конечная вершина ребра уже посещена, пропускаем его
        if (used[v.end]) {
            continue;
        }

        used[v.end] = true;   // Отмечаем конечную вершину ребра как посещенную
        sum += v.weight;   // Добавляем вес ребра к общему весу минимального остовного дерева

        // Обновляем расстояния и добавляем новые ребра в мультисет
        for (auto j : vertices_[v.end].neighbours) {
            if (!used[j.end] && dist[j.end] > j.weight) {
                dist[j.end] = j.weight;
                edges.insert(j);
            }
        }
    }
    return sum;   // Возвращаем общий вес минимального остовного дерева
}

// Основная функция для чтения входных данных, создания графа и выполнения алгоритма Прима
int main() {
    std::cin.tie(nullptr);   // Отключение синхронизации с stdio
    std::cout.tie(nullptr);  // Отключение синхронизации с stdio
    std::istream::sync_with_stdio(false);  // Отключение синхронизации с stdio

    Graph graph;   // Создание экземпляра класса Graph
    std::cin >> graph;   // Чтение входных данных графа
    std::cout << graph.Prim();   // Вывод веса минимального остовного дерева, найденного алгоритмом Прима

    return 0;   // Выход из функции main
}
