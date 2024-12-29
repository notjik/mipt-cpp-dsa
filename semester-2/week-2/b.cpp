#include <iostream>
#include <vector>

class Graph {
private:
    size_t size_;               // Размер графа (количество вершин)
    std::vector<std::vector<int>> table_;  // Матрица смежности для хранения графа

public:
    explicit Graph(size_t size) {
        size_ = size;
        table_.resize(size);      // Изменяем размер вектора до size
        for (auto& i : table_) {
            i.resize(size);         // Изменяем размер каждого внутреннего вектора до size
        }
    }
    ~Graph() = default;

    // Метод для добавления ребра между вершинами i и j
    void Insert(size_t i, size_t j) {
        table_[i][j] = 1;         // Устанавливаем ребро между i и j
        table_[j][i] = 1;         // Устанавливаем ребро между j и i (для неориентированного графа)
    }

    // Метод для получения всех соседних вершин для заданной вершины vertex
    std::vector<int> GetChildren(size_t vertex) {
        std::vector<int> childrens;
        for (size_t i = 0; i < size_; i++) {
            if (table_[vertex][i] == 1) {
                childrens.push_back(i);  // Добавляем вершину i в список соседних вершин
            }
        }
        return childrens;
    }

    // Метод для получения степени вершины vertex (количество инцидентных ей ребер)
    size_t Degree(size_t vertex) {
        return GetChildren(vertex).size();  // Возвращаем размер вектора соседних вершин
    }

    // Метод для подсчета количества ребер в графе
    size_t RoadNumber() {
        size_t sum = 0;
        for (size_t i = 0; i < size_; i++) {
            for (size_t j = i + 1; j < size_; j++) {
                if (table_[i][j] == 1) {
                    sum++;  // Увеличиваем счетчик ребер
                }
            }
        }
        return sum;
    }

    // Метод для печати матрицы смежности графа
    void Print() {
        for (auto& row : table_) {
            for (int val : row) {
                std::cout << val << ' ';  // Выводим каждый элемент матрицы
            }
            std::cout << '\n';           // Переходим на новую строку после вывода строки матрицы
        }
    }
};

int main() {
    size_t n, m;
    std::cin >> n >> m;
    Graph graph(n);  // Создаем граф с n вершинами

    // Ввод ребер графа
    for (size_t i = 0; i < m; i++) {
        int k, l;
        std::cin >> k >> l;
        graph.Insert(k - 1, l - 1);  // Приведение к индексации с нуля
    }

    // Вывод степеней вершин графа
    for (size_t i = 0; i < n; i++) {
        std::cout << graph.Degree(i) << " ";
    }

    return 0;
}
