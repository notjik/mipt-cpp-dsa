#include <iostream>
#include <vector>

// Класс Graph представляет собой граф, реализующий алгоритм Дейкстры
class Graph {
private:
    // Матрица смежности для хранения весов ребер
    std::vector<std::vector<int>> matrix_;
    // Вектор для хранения родительских вершин
    std::vector<int> parent_;
    // Вектор для отслеживания использованных вершин
    std::vector<bool> used_;
    // Вектор для хранения расстояний от начальной вершины до других вершин
    std::vector<int> distance_;

public:
    // Конструктор инициализирует граф с n вершинами
    explicit Graph(int n) {
        matrix_.resize(n);
        // Заполнение матрицы смежности значениями из ввода
        for (auto &row : matrix_) {
            row.resize(n);
            for (int i = 0; i < n; i++) {
                int distance = 0;
                std::cin >> distance;
                row[i] = distance;
            }
        }
        parent_.resize(n, -1); // Инициализация вектора родительских вершин значениями -1
        used_.resize(n, false); // Инициализация вектора использованных вершин значениями false
        distance_.resize(n, 1e6); // Инициализация вектора расстояний значениями 1e6 (бесконечность)
    }

    // Метод для выполнения алгоритма Дейкстры
    void Dijkstra(int start, int end) {
        distance_[start] = 0; // Устанавливаем расстояние до начальной вершины 0
        // Основной цикл алгоритма
        for (int i = 0; i < static_cast<int>(distance_.size()); i++) {
            int v = -1;
            // Поиск неиспользованной вершины с минимальным расстоянием
            for (int j = 0; j < static_cast<int>(distance_.size()); j++) {
                if (!used_[j] && (v == -1 || (distance_[j] < distance_[v]))) {
                    v = j;
                }
            }
            // Если минимальное расстояние равно бесконечности, алгоритм завершен
            if (distance_[v] == 1e6) {
                break;
            }
            used_[v] = true; // Помечаем вершину как использованную
            // Обновление расстояний до соседних вершин
            for (int to = 0; to < static_cast<int>(distance_.size()); to++) {
                if (matrix_[v][to] != -1) {
                    distance_[to] = std::min(distance_[to], distance_[v] + matrix_[v][to]);
                }
            }
        }
        // Если конечная вершина недостижима, выводим -1
        if (distance_[end] == 1e6) {
            std::cout << -1 << '\n';
        } else {
            std::cout << distance_[end] << '\n'; // Выводим кратчайшее расстояние
        }
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0;
    std::cin >> n; // Чтение количества вершин
    int s = 0;
    int f = 0;
    std::cin >> s >> f; // Чтение начальной и конечной вершин
    Graph graph(n); // Создание графа
    graph.Dijkstra(--s, --f); // Запуск алгоритма Дейкстры
    return 0;
}
