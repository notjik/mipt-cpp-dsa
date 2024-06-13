#include <iostream>
#include <vector>

class Graph {
private:
    size_t size_; // Размер графа (количество вершин)
    std::vector<std::vector<int>> table_; // Матрица смежности графа

public:
    // Конструктор графа заданного размера
    explicit Graph(size_t size) {
        size_ = size;
        table_.resize(size); // Изменяем размер вектора для хранения строк матрицы
        for (auto& row : table_) {
            row.resize(size); // Изменяем размер каждой строки для хранения столбцов матрицы
        }
    }

    // Деструктор по умолчанию
    ~Graph() = default;

    // Вставка ребра между вершинами i и j с весом elem
    void Insert(size_t i, size_t j, int elem) {
        table_[i][j] = elem; // Устанавливаем вес ребра от i к j
        table_[j][i] = elem; // Устанавливаем вес ребра от j к i (для неориентированного графа)
    }

    // Сумма весов ребер, соединяющих вершины i, j и k
    int Sum(size_t i, size_t j, size_t k) {
        return table_[i][j] + table_[i][k] + table_[j][k];
    }

    // Получение списка смежных вершин для вершины vertex
    std::vector<int> GetChildren(size_t vertex) {
        std::vector<int> childrens;
        for (size_t i = 0; i < size_; i++) {
            if (table_[vertex][i] == 1) {
                childrens.push_back(i);
            }
        }
        return childrens;
    }

    // Степень вершины (количество смежных вершин)
    size_t Degree(size_t vertex) {
        return GetChildren(vertex).size();
    }

    // Проверка наличия ребра между вершинами from и to
    bool Connected(size_t from, size_t to) {
        return table_[from][to];
    }

    // Подсчет количества ребер в графе
    size_t RoadNumber() {
        size_t sum = 0;
        // Обходим верхний треугольник матрицы смежности (без диагонали)
        for (size_t i = 0; i < size_; i++) {
            for (size_t j = i + 1; j < size_; j++) {
                if (table_[i][j] == 1) {
                    sum++; // Если есть ребро между вершинами i и j, увеличиваем счетчик
                }
            }
        }
        return sum; // Возвращаем общее количество ребер в графе
    }

    // Вывод матрицы смежности графа
    void Print() {
        for (auto& row : table_) {
            for (int elem : row) {
                std::cout << elem << ' '; // Выводим элементы строки матрицы через пробел
            }
            std::cout << '\n'; // Переходим на новую строку после вывода строки матрицы
        }
    }
};

// Основная функция программы
int main() {
    size_t n;
    std::cin >> n; // Вводим количество вершин графа
    Graph graph(n); // Создаем объект класса Graph размера n
    std::vector<int> color(n); // Вектор для хранения цветов вершин (не используется в данном коде)

    // Вводим матрицу смежности графа
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            int elem;
            std::cin >> elem; // Вводим вес ребра между вершинами i и j
            graph.Insert(i, j, elem); // Вставляем ребро в граф
        }
    }

    // Инициализация переменных для нахождения минимального треугольника
    auto ans = static_cast<int>(10e9); // Большое число для начального значения минимальной суммы
    size_t ans_i = 0, ans_j = 0, ans_k = 0; // Индексы вершин минимального треугольника

    // Поиск треугольников в графе
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            for (size_t k = j + 1; k < n; k++) {
                // Проверка на наличие треугольника и обновление минимальной суммы
                if (graph.Connected(i, j) && graph.Connected(j, k) && graph.Connected(k, i) && ans > graph.Sum(i, j, k)) {
                    ans = graph.Sum(i, j, k);
                    ans_i = i;
                    ans_j = j;
                    ans_k = k;
                }
            }
        }
    }

    // Вывод индексов вершин минимального треугольника (1-based index)
    std::cout << ans_i + 1 << ' ' << ans_j + 1 << ' ' << ans_k + 1;
    return 0; // Возвращаем 0, указывая на успешное завершение программы
}
