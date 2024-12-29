#include <iostream>
#include <vector>

class Graph {
private:
    size_t size_;                 // Размер графа (количество вершин)
    std::vector<std::vector<int>> table_;  // Матрица смежности для хранения графа

public:
    explicit Graph(size_t size) {
        size_ = size;
        table_.resize(size);        // Изменяем размер вектора до size (количество строк матрицы)
        for (auto& i : table_) {
            i.resize(size);           // Изменяем размер каждого внутреннего вектора до size (количество столбцов матрицы)
        }
    }
    ~Graph() = default;

    // Метод для добавления ребра между вершинами i и j
    void Insert(size_t i, size_t j) {
        table_[i][j] = 1;           // Устанавливаем ребро между вершинами i и j
        table_[j][i] = 1;           // Граф неориентированный, поэтому устанавливаем ребро и между вершинами j и i
    }

    // Метод для получения всех соседних вершин для заданной вершины vertex
    std::vector<int> GetChildren(size_t vertex) {
        std::vector<int> childrens;
        for (size_t i = 0; i < size_; i++) {
            if (table_[vertex][i] == 1) {
                childrens.push_back(i);  // Добавляем вершину i в список соседних вершин для вершины vertex
            }
        }
        return childrens;
    }

    // Метод для получения степени вершины vertex (количество инцидентных ей ребер)
    size_t Degree(size_t vertex) {
        return GetChildren(vertex).size();  // Возвращаем количество соседних вершин (степень вершины)
    }

    // Метод для проверки наличия ребра между вершинами from и to
    bool Connected(size_t from, size_t to) {
        return table_[from][to];    // Возвращаем значение из матрицы смежности (1 если есть ребро, иначе 0)
    }

    // Метод для подсчета количества ребер в графе
    size_t RoadNumber() {
        size_t sum = 0;
        for (size_t i = 0; i < size_; i++) {
            for (size_t j = i + 1; j < size_; j++) {
                if (table_[i][j] == 1) {
                    sum++;                // Увеличиваем счетчик ребер при нахождении ребра между вершинами i и j
                }
            }
        }
        return sum;
    }

    // Метод для печати матрицы смежности графа
    void Print() {
        for (auto& row : table_) {
            for (int val : row) {
                std::cout << val << ' ';  // Выводим каждый элемент матрицы смежности
            }
            std::cout << '\n';           // Переходим на новую строку после вывода строки матрицы
        }
    }
};

int main() {
    size_t n;
    std::cin >> n;  // Вводим количество вершин графа
    Graph graph(n);  // Создаем граф с n вершинами
    std::vector<int> color(n);  // Вектор для хранения цветов вершин

    // Ввод матрицы смежности и заполнение графа
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            int elem;
            std::cin >> elem;
            if (elem) {
                graph.Insert(i, j);  // Если elem == 1, добавляем ребро между вершинами i и j
            }
        }
    }

    // Ввод цветов вершин
    for (size_t i = 0; i < n; i++) {
        std::cin >> color[i];  // Считываем цвет i-ой вершины
    }

    size_t counter = 0;

    // Проверка ребер на различие цветов вершин
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (graph.Connected(i, j) && (color[i] != color[j])) {
                counter++;  // Увеличиваем счетчик, если есть ребро между вершинами i и j с разными цветами
            }
        }
    }

    std::cout << counter;  // Выводим количество ребер с различными цветами вершин
    return 0;
}
