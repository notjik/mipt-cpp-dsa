#include <iostream>
#include <vector>

// Класс Graph представляет собой граф, реализующий алгоритм Флойда-Уоршелла
class Graph {
private:
    // Матрица смежности для хранения весов ребер
    std::vector<std::vector<int>> matrix_;

public:
    // Метод для выполнения алгоритма Флойда-Уоршелла
    void Floyd();
    // Дружественная функция для перегрузки оператора ввода
    friend std::istream& operator>>(std::istream& is, Graph& graph);
};

// Перегрузка оператора ввода для заполнения матрицы смежности
std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0;
    is >> n; // Считывание количества вершин
    graph.matrix_.resize(n, std::vector<int>(n));
    // Заполнение матрицы смежности значениями из ввода
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            is >> graph.matrix_[i][j];
        }
    }
    return is;
}

// Метод для выполнения алгоритма Флойда-Уоршелла
void Graph::Floyd() {
    int size = static_cast<int>(matrix_.size());
    // Основной тройной цикл алгоритма Флойда-Уоршелла
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                // Обновление минимального расстояния между вершинами i и j через вершину k
                matrix_[i][j] = std::min(matrix_[i][j], matrix_[i][k] + matrix_[k][j]);
            }
        }
    }
    // Вывод обновленной матрицы смежности, содержащей кратчайшие пути
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    Graph graph;
    // Чтение графа из ввода
    std::cin >> graph;
    // Выполнение алгоритма Флойда-Уоршелла и вывод результата
    graph.Floyd();
    return 0;
}
