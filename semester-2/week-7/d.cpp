#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

// Перечисление для цветов вершин, используемое в алгоритме DFS для отслеживания состояния вершины
enum Color { White, Grey, Black };

// Структура для представления вершины графа
struct Vertex {
    int index = 0;                // Индекс вершины
    int time_in = 0;              // Время входа в вершину (для алгоритма DFS)
    int time_up = 0;              // Минимальное время входа, достижимое из вершины (для алгоритма DFS)
    std::vector<int> edges;       // Список смежных вершин
    Color color = White;          // Цвет вершины (White, Grey, Black)
};

// Класс для представления графа
class Graph {
private:
    std::vector<Vertex> vertices_; // Список всех вершин в графе
    std::set<int> points_set_;     // Набор точек сочленения (арт-точек)
    int timer_ = 0;                // Таймер для отслеживания времени входа в вершину в алгоритме DFS

    // Вспомогательный метод для выполнения алгоритма DFS
    void DFS(Vertex& curr, bool is_root);

public:
    // Перегрузка оператора ввода для чтения графа
    friend std::istream& operator>>(std::istream& is, Graph& graph);

    // Метод для поиска и вывода точек сочленения
    void FindPoints();
};

// Перегрузка оператора ввода для чтения графа из входного потока
std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0; // Количество вершин
    int m = 0; // Количество рёбер
    is >> n >> m;
    graph.vertices_.resize(n);
    int begin = 0;
    int end = 0;
    for (int i = 0; i < m; i++) {
        is >> begin >> end;
        --begin; // Переход к нумерации вершин с нуля
        --end;   // Переход к нумерации вершин с нуля

        graph.vertices_[begin].index = begin;
        graph.vertices_[end].index = end;
        graph.vertices_[begin].edges.push_back(end);
        graph.vertices_[end].edges.push_back(begin);
    }
    return is;
}

// Вспомогательный метод для выполнения алгоритма DFS
void Graph::DFS(Vertex& curr, bool is_root) {
    curr.color = Grey;
    curr.time_in = ++timer_;
    curr.time_up = timer_;
    int children_amount = 0; // Количество детей текущей вершины в дереве DFS
    for (int i : curr.edges) {
        if (vertices_[i].color == Grey) {
            // Обновление time_up для текущей вершины
            curr.time_up = std::min(curr.time_up, vertices_[i].time_in);
        }
        if (vertices_[i].color == White) {
            ++children_amount;
            DFS(vertices_[i], false);
            curr.time_up = std::min(curr.time_up, vertices_[i].time_up);

            // Проверка условия для точки сочленения
            if (!is_root && curr.time_in <= vertices_[i].time_up) {
                points_set_.insert(curr.index);
            }
        }
    }

    // Проверка корневой вершины на наличие более одного ребёнка
    if (is_root && children_amount > 1) {
        points_set_.insert(curr.index);
    }
    curr.color = Black;
}

// Метод для поиска и вывода точек сочленения
void Graph::FindPoints() {
    for (auto& vertex : vertices_) {
        if (vertex.color == White) {
            DFS(vertex, true);
        }
    }
    // Вывод количества точек сочленения
    std::cout << points_set_.size() << '\n';
    // Вывод индексов точек сочленения
    for (int point : points_set_) {
        std::cout << point + 1 << '\n'; // Переход к нумерации вершин с единицы для вывода
    }
}

// Главная функция
int main() {
    Graph graph;
    std::cin >> graph; // Чтение графа из стандартного ввода
    graph.FindPoints(); // Поиск и вывод точек сочленения
    return 0;
}
