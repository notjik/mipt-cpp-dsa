#include <iostream>
#include <vector>

// Структура для представления графа
class Graph {
private:
    std::vector<std::vector<int>> vertices_;  // Вектор смежности для хранения вершин
    std::vector<std::vector<int>> edges_;     // Вектор рёбер
    std::vector<bool> used_vertices_;         // Массив для отслеживания посещённых вершин
    std::vector<bool> used_edges_;            // Массив для отслеживания посещённых рёбер
    bool done_ = false;                       // Флаг для отслеживания завершения алгоритма

public:
    // Конструктор с параметрами
    explicit Graph(int n, int m) {
        vertices_.resize(n);                   // Размер вектора вершин устанавливаем равным n
        used_vertices_.resize(n, false);       // Инициализируем массив посещённых вершин
        used_edges_.resize(n, false);          // Инициализируем массив посещённых рёбер

        // Считываем и добавляем рёбра в граф
        for (int i = 0; i < m; i++) {
            int v_1 = 0;
            int v_2 = 0;
            std::cin >> v_1 >> v_2;              // Считываем вершины, соединённые ребром
            edges_.push_back({v_1, v_2});        // Добавляем ребро в вектор рёбер
        }
    }

    // Рекурсивная функция для выполнения DFS
    void DFSBackend(int start) {
        used_vertices_[start] = true;          // Помечаем текущую вершину как посещённую
        for (auto& vertex : vertices_[start]) {
            if (!used_vertices_[vertex]) {       // Если вершина не посещена, рекурсивно запускаем DFS для неё
                DFSBackend(vertex);
            }
        }
    }

    // Функция DFS для обхода графа
    void DFS() {
        std::fill(used_vertices_.begin(), used_vertices_.end(), false);  // Сбрасываем массив посещённых вершин
        DFSBackend(0);                          // Запускаем DFS, начиная с вершины 0
    }

    // Функция для нахождения минимального количества рёбер
    int MinOstrov() {
        int count = 0;                          // Счётчик количества рёбер
        for (auto& edge : edges_) {             // Перебираем все рёбра в графе
            count++;                              // Увеличиваем счётчик на 1
            vertices_[edge[0]].push_back(edge[1]); // Добавляем ребро в вектор смежности для первой вершины
            vertices_[edge[1]].push_back(edge[0]); // Добавляем ребро в вектор смежности для второй вершины

            // Проверяем условие завершения
            if (!done_) {
                used_edges_[edge[0]] = true;        // Помечаем первую вершину ребра как посещённую
                used_edges_[edge[1]] = true;        // Помечаем вторую вершину ребра как посещённую
                bool done = true;                   // Инициализируем флаг done значением true

                // Проверяем, все ли рёбра посещены
                for (auto use : used_edges_) {
                    done &= use;                      // Переменной done присваиваем значение done & use
                    if (!done) {                      // Если done == 0
                        break;                          // Продолжение
                    }
                }
                done_ |= done;                      // В данном случае done_ = done_ | done
            }

            if (done_) {                          // Если done_ == true
                DFS();                              // Выполняем поиск в глубину
                bool done = true;                   // Инициализируем флаг done значением true

                // Проверяем, все ли вершины посещены
                for (auto use : used_vertices_) {
                    done &= use;                      // Переменной done присваиваем значение done & use
                    if (!done) {                      // Если done == 0
                        break;                          // Продолжение
                    }
                }
                if (done) {                         // Если done == true
                    return count;                     // Возвращаем значение count
                }
            }
        }
        return count;                           // Возвращаем значение count
    }
};

int main() {
    std::ios::sync_with_stdio(false);         // Отключаем синхронизацию с потоками C
    std::cin.tie(nullptr);                   // Отключаем связь с std::cin
    int n = 0;                               // Количество вершин
    int m = 0;                               // Количество рёбер
    std::cin >> n >> m;                      // Вводим количество вершин и рёбер
    Graph graph(n, m);                        // Создаём объект класса Graph
    std::cout << graph.MinOstrov();           // Выводим минимальное остовное дерево
    return 0;                                 // Код завершается успешно
}
