#include <iostream>
#include <vector>

// Перечисление для цветов вершин
enum Colors { White, Grey, Black };

// Класс для представления вершины графа
class Vertex {
public:
    Vertex() = default;
    explicit Vertex(int idx) : idx_(idx) {
    }
    Colors color_ = White; // Цвет вершины
    int idx_; // Индекс вершины
};

// Класс для представления графа
class Graph {
private:
    std::vector<std::vector<int>> neighbours_; // Вектор смежности графа
    std::vector<Vertex> vertices_; // Вершины графа
    std::vector<int> component_; // Компоненты связности
    std::vector<int> top_sorted_; // Вершины в топологическом порядке

    // Приватные методы для работы с графом
    void TopSortDFS(Vertex &vertex); // DFS для топологической сортировки
    Graph Reverse(); // Создание обратного графа
    void DFS(Vertex &vertex, int k); // Рекурсивный обход в глубину
    void ClearVertices(); // Сброс цветов вершин

public:
    void TopSort(); // Топологическая сортировка графа
    void FindComponent(); // Поиск компонент связности

    // Перегрузка оператора >> для ввода графа из потока
    friend std::istream &operator>>(std::istream &is, Graph &graph);
};

// Метод DFS для обхода в глубину
void Graph::DFS(Vertex &vertex, int k) {
    vertex.color_ = Grey; // Помечаем вершину как посещенную
    component_[vertex.idx_] = k; // Присваиваем компоненту связности

    // Рекурсивно обходим соседей вершины
    for (auto &i : neighbours_[vertex.idx_]) {
        if (vertices_[i].color_ == White) {
            DFS(vertices_[i], k);
        }
    }
    vertex.color_ = Black; // Помечаем вершину как завершенную
}

// Метод для выполнения топологической сортировки с DFS
void Graph::TopSortDFS(Vertex &vertex) {
    vertex.color_ = Grey; // Помечаем вершину как посещенную
    // Рекурсивно обходим соседей вершины
    for (auto &i : neighbours_[vertex.idx_]) {
        if (vertices_[i].color_ == White) {
            TopSortDFS(vertices_[i]);
        }
    }
    top_sorted_.push_back(vertex.idx_); // Добавляем вершину в топологический порядок
    vertex.color_ = Black; // Помечаем вершину как завершенную
}

// Метод для выполнения топологической сортировки всего графа
void Graph::TopSort() {
    for (size_t i = 0; i < neighbours_.size(); i++) {
        if (vertices_[i].color_ == White) {
            TopSortDFS(vertices_[i]);
        }
    }
    ClearVertices(); // Сбрасываем цвета вершин
}

// Метод для сброса цветов вершин графа
void Graph::ClearVertices() {
    for (auto &i : vertices_) {
        i.color_ = White; // Возвращаем цвет вершин в начальное состояние
    }
}

// Метод для создания обратного графа
Graph Graph::Reverse() {
    Graph copy; // Создаем копию графа
    copy.neighbours_.resize(vertices_.size()); // Инициализируем векторы смежности
    copy.vertices_.resize(vertices_.size()); // Инициализируем вершины
    copy.component_.resize(vertices_.size()); // Инициализируем компоненты связности

    // Заполняем обратные ребра в копии графа
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
        copy.vertices_[i].idx_ = i; // Присваиваем индексы вершинам

        // Для каждой вершины в исходном графе добавляем обратные ребра в копии
        for (int j = 0; j < static_cast<int>(neighbours_[i].size()); j++) {
            copy.neighbours_[neighbours_[i][j]].push_back(i);
        }
    }

    return copy; // Возвращаем обратный граф
}

// Метод для нахождения компонент связности
void Graph::FindComponent() {
    TopSort(); // Выполняем топологическую сортировку
    int k = 0; // Счетчик компонент связности
    Graph reverse_graph = Reverse(); // Создаем обратный граф

    // Обходим вершины в порядке топологической сортировки
    for (int i = static_cast<int>(top_sorted_.size()) - 1; i >= 0; i--) {
        if (reverse_graph.vertices_[top_sorted_[i]].color_ == White) {
            reverse_graph.DFS(reverse_graph.vertices_[top_sorted_[i]], ++k); // Запускаем DFS для компоненты
        }
    }

    // Выводим количество компонент связности
    std::cout << k << '\n';

    // Выводим номера компонент для каждой вершины
    for (auto i : reverse_graph.component_) {
        std::cout << i << " ";
    }
}

// Перегрузка оператора >> для ввода графа из потока
std::istream &operator>>(std::istream &is, Graph &graph) {
    int n = 0; // Количество вершин
    int m = 0; // Количество ребер
    is >> n >> m; // Вводим количество вершин и ребер
    graph.neighbours_.resize(n); // Инициализируем векторы смежности
    graph.vertices_.resize(n); // Инициализируем вершины

    // Для каждой вершины присваиваем индекс
    for (int i = 0; i < n; i++) {
        graph.vertices_[i].idx_ = i;
    }

    // Считываем ребра и добавляем их в векторы смежности
    for (int i = 0; i < m; i++) {
        int from = 0; // Начальная вершина ребра
        int to = 0; // Конечная вершина ребра
        is >> from >> to; // Считываем начальную и конечную вершины
        graph.neighbours_[--from].push_back(--to); // Добавляем ребро в вектор смежности
    }

    return is; // Возвращаем поток
}

// Точка входа в программу
int main() {
    Graph graph; // Создаем объект класса Graph
    std::cin >> graph; // Вводим граф
    graph.FindComponent(); // Находим компоненты связности
    return 0; // Выход из программы
}
