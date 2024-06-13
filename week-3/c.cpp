#include <algorithm>
#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Graph {
private:
    std::vector<std::vector<int>> vertices_; // Список смежности для хранения графа
    std::vector<Colors> colors_; // Цвета вершин (White, Grey, Black)

public:
    // Конструктор графа, принимающий количество вершин n и ребер m
    explicit Graph(int n, int m) {
        vertices_.resize(n); // Изменяем размер списка смежности до n элементов
        colors_.resize(n, White); // Инициализируем все вершины белым цветом
        for (int i = 0; i < m; i++) {
            int src = 0;
            int desc = 0;
            std::cin >> src >> desc; // Вводим ребра графа
            vertices_[--src].push_back(--desc); // Добавляем ребро от src к desc в список смежности
            vertices_[desc].push_back(src); // Добавляем обратное ребро для неориентированного графа
        }
    }

    // Рекурсивная функция обхода графа в глубину (DFS)
    void DFS(int index, std::vector<int> &line) {
        colors_[index] = Grey; // Помечаем текущую вершину как серую (в процессе обхода)
        line.push_back(index); // Добавляем текущую вершину в текущую линию компоненты
        for (auto &i : vertices_[index]) {
            if (colors_[i] == White) { // Если смежная вершина белая, рекурсивно вызываем DFS для нее
                DFS(i, line);
            }
        }
        colors_[index] = Black; // Помечаем текущую вершину как черную (обход завершен)
    }

    // Функция для подсчета и вывода компонент связности графа
    void ComponentCounter() {
        int count = 0; // Счетчик компонент связности
        std::vector<std::vector<int>> result; // Вектор для хранения всех компонент связности
        for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
            if (colors_[i] == White) { // Если вершина белая, значит, она начало новой компоненты
                count++; // Увеличиваем счетчик компонент
                std::vector<int> line; // Создаем новую линию (компоненту связности)
                DFS(i, line); // Запускаем DFS для текущей вершины
                result.push_back(line); // Добавляем найденную компоненту связности в результат
            }
        }
        std::cout << count << '\n'; // Выводим количество компонент связности
        for (auto &line : result) {
            std::cout << line.size() << '\n'; // Выводим размер текущей компоненты связности
            for (auto &i : line) {
                std::cout << i + 1 << ' '; // Выводим вершины текущей компоненты связности с индексацией с 1
            }
            std::cout << '\n';
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); // Ускорение ввода-вывода
    std::cin.tie(nullptr); // Отключение привязки cin к cout
    std::cout.tie(nullptr); // Отключение привязки cout к cin
    int n = 0;
    int m = 0;
    std::cin >> n >> m; // Ввод количества вершин и ребер
    Graph graph(n, m); // Создание объекта графа
    graph.ComponentCounter(); // Подсчет и вывод компонент связности
    return 0;
}
