#include <iostream>
#include <queue>
#include <vector>
#include <climits>

// Класс Edge представляет ребро графа с начальной и конечной вершинами и весом
class Edge {
public:
    Edge(int start, int end_other, int w) : begin(start), end(end_other), weight(w) {}
    int begin;  // Начальная вершина ребра
    int end;    // Конечная вершина ребра
    int weight; // Вес ребра
};

// Класс Vertex представляет вершину графа, содержащую список соседних рёбер
class Vertex {
public:
    std::vector<Edge> neighbours; // Список соседних рёбер
};

// Класс Graph представляет граф, реализующий алгоритм Форда-Беллмана
class Graph {
private:
    std::vector<Vertex> vertices_; // Список вершин графа
    std::vector<int> dist_;        // Список расстояний от стартовой вершины

    // Метод Relax выполняет релаксацию для одного ребра
    bool Relax(Edge& edge);

public:
    // Метод FordBellman выполняет алгоритм Форда-Беллмана и возвращает вектор расстояний
    std::vector<int> FordBellman(int vertex);

    // Дружественная функция для перегрузки оператора ввода
    friend std::istream& operator>>(std::istream& is, Graph& graph);
};

// Перегрузка оператора ввода для заполнения графа
std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0; // Количество вершин
    int m = 0; // Количество рёбер
    is >> n >> m;
    graph.vertices_.resize(n); // Изменение размера списка вершин
    graph.dist_.resize(n, INT_MAX); // Инициализация расстояний значением INT_MAX (бесконечность)

    // Чтение рёбер и добавление их к соответствующим вершинам
    for (int _ = 0; _ < m; _++) {
        int start = 0;
        int end = 0;
        int w = 0;
        is >> start >> end >> w;
        graph.vertices_[start].neighbours.push_back(Edge(start, end, w));
    }
    return is;
}

// Метод Relax выполняет релаксацию для одного ребра
bool Graph::Relax(Edge& edge) {
    int from = edge.begin;
    int to = edge.end;
    int weight = edge.weight;
    // Проверка, можно ли улучшить расстояние до вершины 'to' через вершину 'from'
    if ((dist_[from] != INT_MAX) && (dist_[to] > dist_[from] + weight)) {
        dist_[to] = dist_[from] + weight; // Улучшение расстояния
        return true;
    }
    return false;
}

// Метод FordBellman выполняет алгоритм Форда-Беллмана и возвращает вектор расстояний
std::vector<int> Graph::FordBellman(int vertex) {
    dist_[vertex] = 0; // Установка начального расстояния до стартовой вершины в 0
    int size = static_cast<int>(vertices_.size());
    // Основной цикл алгоритма Форда-Беллмана
    for (int i = 0; i < size - 1; i++) {
        bool loop = false;
        // Обход всех вершин и их соседних рёбер
        for (int vertex = 0; vertex < size; vertex++) {
            for (Edge& neighbour : vertices_[vertex].neighbours) {
                loop |= Relax(neighbour); // Выполнение релаксации для каждого ребра
            }
        }
        // Если ни одной релаксации не произошло, выходим из цикла
        if (!loop) {
            return dist_;
        }
    }
    return dist_; // Возврат вектора расстояний
};

int main() {
    Graph graph;
    std::cin >> graph; // Чтение графа из ввода
    std::vector<int> answer = graph.FordBellman(0); // Выполнение алгоритма Форда-Беллмана
    // Вывод расстояний от начальной вершины до всех остальных
    for (auto elem : answer) {
        std::cout << elem << " ";
    }
    return 0;
}
