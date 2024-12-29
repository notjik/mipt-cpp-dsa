#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// Перечисление для цветов вершин, используемое в алгоритме DFS для отслеживания состояния вершины
enum Color { White, Grey, Black };

// Структура для представления вершины графа
struct Vertex {
    int index;       // Индекс вершины
    int time_in = 0; // Время входа в вершину (для алгоритма поиска мостов)
    int time_up = 0; // Минимальное время входа, достижимое из вершины (для алгоритма поиска мостов)
    Color color = White; // Цвет вершины (White, Grey, Black)
};

// Класс для представления графа
class Graph {
private:
    std::vector<Vertex> vertices_;           // Список вершин графа
    std::vector<std::vector<int>> neighbours_; // Список смежности для хранения смежных вершин каждой вершины
    std::vector<std::pair<int, int>> edges_;   // Список рёбер графа в виде пар вершин
    std::set<std::ptrdiff_t> bridges_;       // Набор индексов рёбер-мостов
    int timer_ = 0;                          // Таймер для отслеживания времени входа в вершины в алгоритме DFS

    // Вспомогательная функция DFS для поиска мостов
    void DFS(int curr, int parent);

public:
    // Перегрузка оператора ввода для чтения графа
    friend std::istream& operator>>(std::istream& is, Graph& graph);

    // Метод для поиска и вывода мостов графа
    void FindBridges();
};

// Перегрузка оператора ввода для чтения графа из входного потока
std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0; // Количество вершин
    int m = 0; // Количество рёбер
    is >> n >> m;
    graph.vertices_.resize(n);               // Инициализация списка вершин
    graph.neighbours_.resize(n);             // Инициализация списка смежности
    graph.edges_.resize(m);                  // Инициализация списка рёбер
    int begin = 0;
    int end = 0;
    for (int i = 0; i < m; i++) {
        is >> begin >> end;
        --begin; // Переход к нумерации вершин с нуля
        --end;   // Переход к нумерации вершин с нуля
        if (begin == end) {
            continue; // Игнорирование петель (вершина инцидентна сама себе)
        }

        // Заполнение информации о ребре в списках смежности и рёбер
        graph.vertices_[begin].index = begin;
        graph.vertices_[end].index = end;
        graph.neighbours_[begin].push_back(end);
        graph.neighbours_[end].push_back(begin);
        graph.edges_[i] = {begin, end};
    }
    return is;
}

// Вспомогательная функция DFS для поиска мостов
void Graph::DFS(int curr, int parent) {
    vertices_[curr].color = Grey;     // Окраска текущей вершины в серый цвет
    vertices_[curr].time_in = ++timer_; // Установка времени входа
    vertices_[curr].time_up = timer_;   // Изначально time_up равно времени входа

    // Обход смежных вершин
    for (int next : neighbours_[curr]) {
        if (next == parent) {
            continue; // Пропуск обратного ребра к родительской вершине
        }
        if (vertices_[next].color == Grey) {
            // Если смежная вершина уже была посещена, обновляем time_up текущей вершины
            vertices_[curr].time_up = std::min(vertices_[curr].time_up, vertices_[next].time_in);
        }
        if (vertices_[next].color == White) {
            // Если смежная вершина белая, рекурсивно запускаем DFS
            DFS(next, curr);
            // После завершения DFS обновляем time_up текущей вершины
            vertices_[curr].time_up = std::min(vertices_[curr].time_up, vertices_[next].time_up);

            // Проверяем, является ли ребро (curr, next) мостом
            if (vertices_[curr].time_in < vertices_[next].time_up) {
                // Находим индекс ребра в списке рёбер
                auto it = std::find_if(edges_.begin(), edges_.end(),
                                       [curr, next](const std::pair<int, int>& edge) {
                                           return (edge.first == curr && edge.second == next) ||
                                                  (edge.first == next && edge.second == curr);
                                       });
                if (it != edges_.end()) {
                    // Если ребро является мостом, добавляем его индекс в набор мостов
                    bridges_.insert(std::distance(edges_.begin(), it));
                }
            }
        }
    }

    vertices_[curr].color = Black; // После обработки всех смежных вершин окрашиваем вершину в черный цвет
}

// Метод для поиска и вывода мостов графа
void Graph::FindBridges() {
    // Обход всех вершин и запуск DFS для непосещённых вершин
    for (auto& vertex : vertices_) {
        if (vertex.color == White) {
            DFS(vertex.index, -1); // Запуск DFS для текущей вершины
        }
    }

    // Вывод количества найденных мостов
    std::cout << bridges_.size() << '\n';
    // Вывод индексов мостов (увеличенных на 1 для приведения к единой нумерации с входа)
    for (std::ptrdiff_t bridge_index : bridges_) {
        std::cout << bridge_index + 1 << ' ';
    }
}

// Главная функция программы
int main() {
    // Ускорение ввода-вывода для ускорения работы программы
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Graph graph; // Создание объекта класса Graph
    std::cin >> graph; // Чтение графа из стандартного ввода
    graph.FindBridges(); // Поиск и вывод мостов графа
    return 0;
}
