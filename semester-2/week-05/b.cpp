#include <iostream>
#include <queue>
#include <vector>
#include <climits>

// Класс Graph представляет собой граф с взвешенными ребрами
class Graph {
private:
    // Матрица смежности для хранения весов ребер
    std::vector<std::vector<int>> vertices_;
    // Вектор расстояний от начальной вершины до других вершин
    std::vector<int> distances_;
    // Переменная для хранения максимального веса ребра
    int max_weight_;

public:
    // Конструктор инициализирует граф с n вершинами и m ребрами
    explicit Graph(int n, int m) {
        vertices_.resize(n, std::vector<int>(n, 0)); // Инициализируем матрицу смежности нулями
        distances_.resize(n, INT_MAX); // Инициализируем расстояния значением INT_MAX (бесконечность)
        max_weight_ = 0; // Изначально максимальный вес ребра равен нулю
        // Чтение m ребер
        for (int i = 0; i < m; i++) {
            int from = 0;
            int to = 0;
            int weight = 0;
            std::cin >> from >> to >> weight;
            vertices_[--from][--to] = weight; // Заполняем матрицу смежности
            max_weight_ = std::max(max_weight_, weight); // Обновляем максимальный вес ребра
        }
    }

    // Метод для выполнения модифицированного BFS для поиска кратчайшего пути
    void BFS(int source, int destination) {
        int size = max_weight_ * static_cast<int>(vertices_.size()); // Максимально возможное расстояние
        std::vector<std::queue<int>> queues(size); // Массив очередей
        queues[0].push(source); // Добавляем начальную вершину в очередь с приоритетом 0
        distances_[source] = 0; // Расстояние до начальной вершины 0
        // Проходим по всем возможным расстояниям
        for (int d = 0; d < size; d++) {
            while (!queues[d].empty()) {
                int v = queues[d].front(); // Берем вершину из очереди
                queues[d].pop(); // Удаляем вершину из очереди
                if (distances_[v] < d) {
                    continue; // Если текущее расстояние меньше d, пропускаем
                }
                // Проходим по всем соседям текущей вершины
                for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
                    if (vertices_[v][i] == 0) {
                        continue; // Пропускаем, если нет ребра
                    }
                    // Если найдено более короткое расстояние до вершины i
                    if (distances_[i] > distances_[v] + vertices_[v][i]) {
                        distances_[i] = distances_[v] + vertices_[v][i]; // Обновляем расстояние
                        queues[distances_[i]].push(i); // Добавляем вершину в очередь с приоритетом distances_[i]
                    }
                }
            }
        }
        // Если конечная вершина недостижима, выводим -1
        if (distances_[destination] == INT_MAX) {
            std::cout << -1;
        } else {
            std::cout << distances_[destination]; // Выводим кратчайшее расстояние
        }
    }
};

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m; // Чтение количества вершин и ребер
    // Если ребер нет, путь невозможен, выводим -1
    if (m == 0) {
        std::cout << -1;
        return 0;
    }
    int start = 0;
    int end = 0;
    std::cin >> start >> end; // Чтение начальной и конечной вершин
    Graph graph(n, m); // Создание графа
    graph.BFS(--start, --end); // Поиск и вывод кратчайшего пути
    return 0;
}
