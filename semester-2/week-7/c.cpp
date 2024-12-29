#include <iostream>
#include <vector>
#include <climits>

// Класс для представления ребра графа
class Edge {
public:
    // Конструктор инициализирует начало, конец и вес ребра
    explicit Edge(int b, int e, int w) : begin(b), end(e), weight(w) {}
    int begin;  // Начальная вершина ребра
    int end;    // Конечная вершина ребра
    int weight; // Вес ребра
};

// Класс для представления графа
class Graph {
private:
    std::vector<Edge> edges_;          // Список всех рёбер в графе
    std::vector<int> distances_;       // Вектор для хранения минимальных расстояний от начальной вершины
    int num_of_vertex_;                // Количество вершин в графе
    bool Relax(Edge& edge);            // Вспомогательный метод для релаксации ребра

public:
    std::vector<int> FordBellman(int vertex); // Метод для выполнения алгоритма Форда-Беллмана
    friend std::istream& operator>>(std::istream& is, Graph& graph); // Перегрузка оператора ввода для чтения графа
};

// Перегрузка оператора ввода для чтения графа
std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0;
    int m = 0;
    is >> n >> m;  // Чтение количества вершин и рёбер
    graph.distances_.resize(n, INT_MAX);  // Инициализация вектора расстояний значениями INT_MAX
    graph.num_of_vertex_ = n;  // Установка количества вершин
    for (int i = 0; i < m; i++) {
        int begin = 0;
        int end = 0;
        int weight = 0;
        is >> begin >> end >> weight;  // Чтение начала, конца и веса ребра
        graph.edges_.emplace_back(--begin, --end, weight);  // Добавление ребра в список рёбер
    }
    return is;
}

// Метод для релаксации ребра
bool Graph::Relax(Edge& edge) {
    // Проверка, что текущий путь короче найденного ранее
    if ((distances_[edge.begin] != INT_MAX) && (distances_[edge.end] > distances_[edge.begin] + edge.weight)) {
        distances_[edge.end] = distances_[edge.begin] + edge.weight;  // Обновление расстояния
        return true;
    }
    return false;
}

// Метод для выполнения алгоритма Форда-Беллмана
std::vector<int> Graph::FordBellman(int vertex) {
    distances_[vertex] = 0;  // Установка начальной вершины с расстоянием 0
    // Повторение алгоритма |V| - 1 раз
    for (int i = 0; i < num_of_vertex_ - 1; ++i) {
        for (auto& edge : edges_) {
            Relax(edge);  // Релаксация каждого ребра
        }
    }
    return distances_;  // Возвращение вектора минимальных расстояний
}

int main() {
    Graph graph;
    std::cin >> graph;  // Чтение графа из стандартного ввода
    std::vector<int> answer = graph.FordBellman(0);  // Выполнение алгоритма Форда-Беллмана с начальной вершиной 0
    for (auto v : answer) {
        if (v == INT_MAX) {
            std::cout << 30000 << ' ';  // Замена INT_MAX на 30000 для вывода
            continue;
        }
        std::cout << v << ' ';  // Вывод минимальных расстояний
    }
    return 0;
}
