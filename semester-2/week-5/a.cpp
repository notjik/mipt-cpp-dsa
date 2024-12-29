#include <iostream>
#include <list>
#include <queue>
#include <vector>

// Класс Graph представляет собой неориентированный граф
class Graph {
private:
    // Вектор смежности для хранения вершин и их соседей
    std::vector<std::vector<int>> vertices_;
    // Вектор расстояний от начальной вершины до других вершин
    std::vector<int> distance_;
    // Вектор родителей для восстановления пути
    std::vector<int> parents_;

public:
    // Конструктор инициализирует граф с n вершинами и m ребрами
    Graph(int n, int m) {
        distance_.resize(n, -1); // Инициализируем расстояния значением -1 (неизвестное расстояние)
        vertices_.resize(n); // Инициализируем вектор смежности для n вершин
        parents_.resize(n, -1); // Инициализируем вектор родителей значением -1 (нет родителя)
        // Чтение m ребер
        for (int i = 0; i < m; i++) {
            int first = 0;
            int second = 0;
            std::cin >> first >> second;
            vertices_[--first].push_back(--second); // Добавляем ребро first -> second
            vertices_[second].push_back(first); // Добавляем ребро second -> first (граф неориентированный)
        }
    }
    // Метод для выполнения BFS (поиска в ширину)
    int BFS(int vertex, int destination);
    // Метод для поиска кратчайшего пути
    void FindShortestWay(int start, int end);
};

// Метод BFS выполняет поиск в ширину от вершины vertex до вершины destination
int Graph::BFS(int vertex, int destination) {
    std::queue<int> queue; // Очередь для хранения вершин
    distance_[vertex] = 0; // Расстояние до начальной вершины 0
    parents_[vertex] = vertex; // Начальная вершина является своим собственным родителем
    queue.push(vertex); // Добавляем начальную вершину в очередь
    // Пока очередь не пуста
    while (!queue.empty()) {
        int parent = queue.front();
        queue.pop();
        // Проходим по всем соседям текущей вершины
        for (int i : vertices_[parent]) {
            // Если соседняя вершина еще не посещена
            if (distance_[i] == -1) {
                queue.push(i); // Добавляем вершину в очередь
                parents_[i] = parent; // Устанавливаем родителя для текущей вершины
                distance_[i] = distance_[parent] + 1; // Увеличиваем расстояние от начальной вершины
            }
        }
    }
    return distance_[destination]; // Возвращаем расстояние до конечной вершины
}

// Метод FindShortestWay находит и выводит кратчайший путь от start до end
void Graph::FindShortestWay(int start, int end) {
    int distance = BFS(start, end); // Выполняем BFS для поиска кратчайшего пути
    // Если конечная вершина достижима
    if (parents_[end] != -1) {
        std::vector<int> path; // Вектор для хранения пути
        int current = end;
        // Восстанавливаем путь от конечной вершины к начальной
        while (parents_[current] != current) {
            path.push_back(current);
            current = parents_[current];
        }
        std::cout << distance << '\n'; // Выводим длину кратчайшего пути
        std::cout << start + 1 << ' '; // Выводим начальную вершину (учитываем 1-индексацию)
        // Выводим путь в обратном порядке
        for (int i = static_cast<int>(path.size() - 1); i >= 0; i--) {
            std::cout << path.at(i) + 1 << ' '; // Учитываем 1-индексацию
        }
    } else {
        std::cout << -1; // Если путь не найден, выводим -1
    }
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m; // Чтение количества вершин и ребер
    int a = 0;
    int b = 0;
    std::cin >> a >> b; // Чтение начальной и конечной вершин
    Graph graph(n, m); // Создание графа
    graph.FindShortestWay(--a, --b); // Поиск и вывод кратчайшего пути
    return 0;
}
