#include <iostream>
#include <vector>
#include <climits> // Для использования INT_MAX

class Graph {
private:
    std::vector<std::vector<int>> matrix_; // Матрица смежности графа
    std::vector<int> parent_; // Вектор для хранения предков вершин
    std::vector<bool> used_; // Вектор для отслеживания посещенных вершин
    std::vector<int> distance_; // Вектор для хранения расстояний от начальной вершины

public:
    // Конструктор, который принимает количество вершин графа
    explicit Graph(int n) {
        matrix_.resize(n);
        for (auto &row : matrix_) {
            row.resize(n);
            for (int i = 0; i < n; i++) {
                int distance = 0;
                std::cin >> distance; // Считывание расстояния между вершинами
                row[i] = distance;
            }
        }
        parent_.resize(n, -1); // Инициализация вектора предков значением -1
        used_.resize(n, false); // Инициализация вектора посещенных вершин значением false
        distance_.resize(n, INT_MAX); // Инициализация вектора расстояний значением INT_MAX (бесконечность)
    }

    // Метод для выполнения алгоритма Дейкстры
    void Dijkstra(int start, int end) {
        distance_[start] = 0; // Устанавливаем расстояние до начальной вершины равным 0
        for (int i = 0; i < static_cast<int>(distance_.size()); i++) {
            int v = -1;
            // Поиск непосещенной вершины с минимальным расстоянием
            for (int j = 0; j < static_cast<int>(distance_.size()); j++) {
                if (!used_[j] && (v == -1 || (distance_[j] < distance_[v]))) {
                    v = j;
                }
            }
            // Если минимальное расстояние равно INT_MAX, прерываем цикл
            if (distance_[v] == INT_MAX) {
                break;
            }
            used_[v] = true; // Помечаем вершину как посещенную
            // Обновление расстояний до соседних вершин
            for (int to = 0; to < static_cast<int>(distance_.size()); to++) {
                if (matrix_[v][to] != -1) {
                    distance_[to] = std::min(distance_[to], distance_[v] + matrix_[v][to]);
                }
            }
        }
        // Вывод результата
        if (distance_[end] == INT_MAX) {
            std::cout << -1 << '\n'; // Если путь не найден, выводим -1
        } else {
            std::cout << distance_[end] << '\n'; // Иначе выводим длину кратчайшего пути
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0; // Количество вершин
    std::cin >> n;
    int s = 0; // Начальная вершина
    int f = 0; // Конечная вершина
    std::cin >> s >> f;
    Graph graph(n); // Создание графа с n вершинами
    graph.Dijkstra(--s, --f); // Вызов алгоритма Дейкстры
    return 0;
}
