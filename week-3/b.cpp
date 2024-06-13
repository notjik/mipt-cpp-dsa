#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Graph {
private:
    std::vector<std::vector<int>> vertices_; // Список смежности для хранения графа
    std::vector<Colors> colors_; // Цвета вершин (White, Grey, Black)
    std::vector<int> parents_; // Родители вершин для поиска цикла
    std::vector<int> cycle_; // Вектор для хранения найденного цикла

public:
    // Конструктор графа, принимающий количество вершин n и ребер m
    explicit Graph(int n, int m) {
        vertices_.resize(n); // Изменяем размер списка смежности до n элементов
        colors_.resize(n, White); // Инициализируем все вершины белым цветом
        parents_.resize(n, -1); // Инициализируем всех родителей как -1 (нет родителя)
        for (int i = 0; i < m; i++) {
            int src = 0;
            int desc = 0;
            std::cin >> src >> desc; // Вводим ребра графа
            vertices_[--src].push_back(--desc); // Добавляем ребро от src к desc в список смежности
        }
    }

    // Рекурсивная функция обхода графа в глубину (DFS)
    void DFS(int index) {
        colors_[index] = Grey; // Помечаем текущую вершину как серую (в процессе обхода)
        for (auto& i : vertices_[index]) {
            if (colors_[i] == White) { // Если смежная вершина белая, рекурсивно вызываем DFS для нее
                DFS(i);
            }
        }
        colors_[index] = Black; // Помечаем текущую вершину как черную (обход завершен)
    }

    // Функция для проверки наличия цикла, начиная с вершины index
    bool IsCycleExist(int index, int& start, int& end) {
        colors_[index] = Grey; // Помечаем текущую вершину как серую
        for (auto& i : vertices_[index]) {
            if (colors_[i] == Grey) { // Если находим серую вершину, значит, обнаружен цикл
                start = i; // Начало цикла
                end = index; // Конец цикла
                return true;
            }
            if (colors_[i] == White) {
                parents_[i] = index; // Записываем текущую вершину как родителя для смежной
                if (IsCycleExist(i, start, end)) { // Рекурсивно ищем цикл
                    return true;
                }
            }
        }
        colors_[index] = Black; // Помечаем текущую вершину как черную (обход завершен)
        return false;
    }

    // Функция для поиска и вывода цикла в графе, если он есть
    void FindCycle() {
        int start = -1;
        int end = 0;
        for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
            if (colors_[i] == White && IsCycleExist(i, start, end)) { // Находим первую компоненту с циклом
                break;
            }
        }
        if (start == -1) {
            std::cout << "NO"; // Если цикл не найден, выводим NO
        } else {
            for (int vertex = end; vertex != start; vertex = parents_[vertex]) {
                cycle_.push_back(vertex); // Добавляем вершины цикла в вектор
            }
            cycle_.push_back(start); // Добавляем стартовую вершину цикла
            std::cout << "YES" << '\n'; // Выводим YES
            for (int i = static_cast<int>(cycle_.size()) - 1; i >= 0; i--) {
                std::cout << cycle_[i] + 1 << " "; // Выводим вершины цикла с учетом индексации с 1
            }
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
    graph.FindCycle(); // Поиск и вывод цикла в графе
    return 0;
}
