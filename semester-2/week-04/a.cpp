#include <iostream>
#include <list>
#include <vector>

enum Colors { White, Grey, Black };

class NoCycle : public std::exception {
    const char* what() const noexcept override {
        return "No cycle!";
    }
};

class CycleExist : public std::exception {
    const char* what() const noexcept override {
        return "Cycle!";
    }
};

class Graph {
private:
    std::vector<std::vector<int>> vertices_; // Список смежности для хранения графа
    std::vector<Colors> colors_; // Цвета вершин (White, Grey, Black)
    std::vector<int> parents_; // Родители вершин в процессе обхода
    using Cycle = std::vector<int>; // Тип для представления цикла

public:
    // Перегрузка оператора ввода для графа
    friend std::istream& operator>>(std::istream& is, Graph& graph) {
        int n = 0;
        int m = 0;
        is >> n >> m; // Вводим количество вершин и ребер
        graph.vertices_.resize(n); // Изменяем размер списка смежности до n элементов
        graph.colors_.resize(n, White); // Инициализируем все вершины белым цветом
        graph.parents_.resize(n, -1); // Инициализируем родителей вершин

        for (int i = 0; i < m; i++) {
            int from = 0;
            int to = 0;
            is >> from >> to; // Вводим ребро графа
            graph.vertices_[--from].push_back(--to); // Добавляем ребро от вершины from к вершине to
        }

        return is;
    }

    // Рекурсивная функция обхода графа в глубину (DFS) для поиска цикла
    bool IsCycleExist(int index, Cycle& result) {
        colors_[index] = Grey; // Помечаем текущую вершину как серую (в процессе обхода)
        for (auto& i : vertices_[index]) {
            if (colors_[i] == Grey) { // Если смежная вершина серая, то есть цикл
                result.push_back(i); // Добавляем вершину в результат (часть цикла)
                result.push_back(index); // Добавляем текущую вершину в результат (часть цикла)
                return true;
            }
            if (colors_[i] == White) { // Если смежная вершина белая, рекурсивно вызываем DFS для нее
                parents_[i] = index; // Запоминаем текущую вершину как родителя
                if (IsCycleExist(i, result)) {
                    return true;
                }
            }
        }
        colors_[index] = Black; // Помечаем текущую вершину как черную (обход завершен)
        return false;
    }

    // Функция для обнаружения цикла в графе
    void DetectCycle() {
        for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
            if (colors_[i] == White) { // Если вершина белая, запускаем DFS для проверки цикла
                Cycle result;
                if (IsCycleExist(i, result)) {
                    throw CycleExist(); // Если найден цикл, выбрасываем исключение
                }
            }
        }
    }

    // Рекурсивная функция обхода графа в глубину (DFS) для топологической сортировки
    void TopSortDFS(int index, std::vector<int>& answer) {
        colors_[index] = Grey; // Помечаем текущую вершину как серую (в процессе обхода)
        for (auto& i : vertices_[index]) {
            if (colors_[i] == Grey) { // Если смежная вершина серая, значит, найден цикл
                throw CycleExist(); // Выбрасываем исключение, так как граф содержит цикл
            }
            if (colors_[i] == White) { // Если смежная вершина белая, рекурсивно вызываем DFS для нее
                TopSortDFS(i, answer);
            }
        }
        colors_[index] = Black; // Помечаем текущую вершину как черную (обход завершен)
        answer.push_back(index); // Добавляем текущую вершину в конец списка ответа
    }

    // Функция для топологической сортировки графа
    std::vector<int> TopSort() {
        std::vector<int> answer; // Вектор для хранения топологически отсортированных вершин
        for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
            if (colors_[i] == White) { // Если вершина белая, запускаем DFS для топологической сортировки
                TopSortDFS(i, answer);
            }
        }
        std::reverse(answer.begin(), answer.end()); // Разворачиваем вектор, чтобы получить правильный порядок
        return answer;
    }
};

int main() {
    Graph graph; // Создаем объект графа
    try {
        std::cin >> graph; // Вводим граф
        graph.DetectCycle(); // Проверяем наличие циклов в графе
        std::vector<int> top_sorted = graph.TopSort(); // Получаем топологически отсортированные вершины
        for (auto i : top_sorted) {
            std::cout << i + 1 << " "; // Выводим вершины с индексацией с 1
        }
    } catch (CycleExist err) {
        std::cout << -1; // Если граф содержит цикл, выводим -1
    }
    return 0;
}
