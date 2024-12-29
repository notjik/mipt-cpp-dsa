#include <iostream>
#include <vector>
#include <algorithm> // Для std::min

class Graph {
private:
    std::vector<std::vector<int>> matrix_; // Матрица смежности для хранения весов ребер

public:
    // Метод для выполнения алгоритма Флойда-Уоршелла
    void Floyd();
    // Перегрузка оператора ввода для чтения графа из входного потока
    friend std::istream& operator>>(std::istream& is, Graph& graph);
};

// Перегрузка оператора ввода для чтения графа
std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0;
    is >> n; // Чтение количества вершин
    graph.matrix_.resize(n, std::vector<int>(n)); // Изменение размера матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            is >> graph.matrix_[i][j]; // Чтение весов ребер
        }
    }
    return is;
}

// Реализация алгоритма Флойда-Уоршелла
void Graph::Floyd() {
    int size = static_cast<int>(matrix_.size());
    // Тройной вложенный цикл для обновления матрицы смежности
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                // Обновление значения matrix_[i][j] если найден более короткий путь через вершину k
                matrix_[i][j] = std::min(matrix_[i][j], matrix_[i][k] + matrix_[k][j]);
            }
        }
    }
    // Вывод результирующей матрицы кратчайших расстояний
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    Graph graph;
    std::cin >> graph; // Чтение графа из входного потока
    graph.Floyd(); // Выполнение алгоритма Флойда-Уоршелла
    return 0;
}
