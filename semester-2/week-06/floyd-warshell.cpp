#include <iostream>
#include <vector>
#include <algorithm> // для std::min
#include <climits>   // для INT_MAX

class Graph {
private:
    std::vector<std::vector<int>> matrix_; // Матрица смежности графа

public:
    void Floyd(); // Метод для выполнения алгоритма Флойда-Уоршелла
    friend std::istream& operator>>(std::istream& is, Graph& graph); // Перегрузка оператора ввода для заполнения графа
};

// Перегрузка оператора ввода для заполнения графа
std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0;
    is >> n; // Чтение количества вершин графа
    graph.matrix_.resize(n, std::vector<int>(n)); // Изменение размера матрицы смежности
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            is >> graph.matrix_[i][j]; // Чтение веса ребра
            // Если граф содержит 0 в матрице смежности, кроме диагонали, заменяем его на бесконечность (нет пути)
            if (graph.matrix_[i][j] == 0 && i != j) {
                graph.matrix_[i][j] = INT_MAX;
            }
        }
    }
    return is;
}

// Реализация алгоритма Флойда-Уоршелла
void Graph::Floyd() {
    int size = static_cast<int>(matrix_.size()); // Получение размера матрицы (количество вершин)
    // Основной тройной цикл алгоритма Флойда-Уоршелла
    for (int k = 0; k < size; k++) { // Перебор всех промежуточных вершин
        for (int i = 0; i < size; i++) { // Перебор всех начальных вершин
            for (int j = 0; j < size; j++) { // Перебор всех конечных вершин
                // Проверка на наличие пути через вершину k
                if (matrix_[i][k] != INT_MAX && matrix_[k][j] != INT_MAX) {
                    matrix_[i][j] = std::min(matrix_[i][j], matrix_[i][k] + matrix_[k][j]);
                }
            }
        }
    }
    // Вывод матрицы кратчайших путей
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix_[i][j] == INT_MAX) {
                std::cout << "INF "; // Если пути нет, выводим INF
            } else {
                std::cout << matrix_[i][j] << ' '; // Выводим значение кратчайшего пути
            }
        }
        std::cout << '\n'; // Переход на новую строку для следующей строки матрицы
    }
}

int main() {
    Graph graph; // Создание объекта графа
    std::cin >> graph; // Заполнение графа через перегруженный оператор >>
    graph.Floyd(); // Вызов алгоритма Флойда-Уоршелла
    return 0;
}
