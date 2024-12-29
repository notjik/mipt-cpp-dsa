#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Функция для удаления ребер, соответствующих пути из графа
void Remove(std::vector<std::vector<int>>& graph, const std::vector<int>& path) {
    // Проходим по всем ребрам в пути
    for (int i = 0; i < static_cast<int>(path.size()) - 1; i++) {
        auto& edges = graph[path[i]]; // Получаем список смежности для текущей вершины
        // Удаляем ребро, соединяющее текущую вершину с следующей в пути
        edges.erase(std::remove(edges.begin(), edges.end(), path[i + 1]), edges.end());
    }
}

// Функция для поиска пути в графе от вершины s до вершины t с помощью BFS
std::vector<int> BFS(const std::vector<std::vector<int>>& graph, int s, int t) {
    std::vector<bool> visited(graph.size(), false); // Вектор для отслеживания посещенных вершин
    std::queue<int> queue; // Очередь для BFS
    std::vector<int> parents(graph.size(), -1); // Вектор для хранения предков вершин для восстановления пути
    queue.push(s); // Начинаем поиск с вершины s
    visited[s] = true; // Отмечаем вершину s как посещенную

    // Основной цикл BFS
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        // Если достигли вершины t, выходим из цикла
        if (current == t) {
            break;
        }

        // Проходим по всем смежным вершинам
        for (int next : graph[current]) {
            if (!visited[next]) { // Если вершина не посещена
                parents[next] = current; // Запоминаем предка
                visited[next] = true; // Отмечаем вершину как посещенную
                queue.push(next); // Добавляем вершину в очередь
            }
        }
    }

    std::vector<int> path;
    // Если вершина t не была посещена, возвращаем пустой путь
    if (!visited[t]) {
        return path;
    }

    // Восстанавливаем путь от t до s с помощью предков
    for (int v = t; v != -1; v = parents[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end()); // Переворачиваем путь, чтобы получить его в правильном порядке
    return path;
}

int main() {
    int n = 0; // Количество вершин
    int m = 0; // Количество ребер
    int s = 0; // Начальная вершина
    int t = 0; // Конечная вершина
    std::cin >> n >> m >> s >> t;
    std::vector<std::vector<int>> graph(n); // Список смежности для графа

    // Считываем ребра графа
    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        std::cin >> x >> y;
        graph[x].push_back(y); // Добавляем ребро x -> y
    }

    // Ищем первый путь от s до t
    std::vector<int> path1 = BFS(graph, s, t);
    // Удаляем ребра, соответствующие первому пути
    Remove(graph, path1);
    // Ищем второй путь от s до t
    std::vector<int> path2 = BFS(graph, s, t);

    // Если один из путей пуст, выводим "NO"
    if (path1.empty() || path2.empty()) {
        std::cout << "NO\n";
        return 0;
    }

    // Если оба пути найдены, выводим "YES" и оба пути
    std::cout << "YES\n";
    for (int v : path1) {
        std::cout << v << " ";
    }
    std::cout << "\n";
    for (int v : path2) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    return 0;
}
