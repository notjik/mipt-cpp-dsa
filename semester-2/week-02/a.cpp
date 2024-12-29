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

    // Вставка ребра между вершинами i и j с весом elem
    void Insert(size_t i, size_t j, int elem) {
        table_[i][j] = elem; // Устанавливаем вес ребра от i к j
        table_[j][i] = elem; // Устанавливаем вес ребра от j к i (для неориентированного графа)
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

    // Вводим матрицу смежности графа
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            int input;
            std::cin >> input; // Вводим вес ребра между вершинами i и j
            graph.Insert(i, j, input); // Вставляем ребро в граф
        }
    }

    // Выводим количество ребер в графе
    std::cout << graph.RoadNumber();

    return 0; // Возвращаем 0, указывая на успешное завершение программы
}
