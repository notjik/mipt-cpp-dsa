#include <iostream>
#include <list>
#include <vector>

enum Colors { White, Grey, Black };

// Исключение, сигнализирующее об отсутствии цикла в графе
class NoCycle : public std::exception {
    const char* what() const noexcept override { return "No cycle!"; }
};

// Исключение, сигнализирующее о наличии цикла в графе
class CycleExist : public std::exception {
    const char* what() const noexcept override { return "Cycle!"; }
};

class Graph {
private:
    std::vector<std::vector<int>> vertices; // Вектор смежности графа
    std::vector<Colors> colors; // Цвета вершин
    std::vector<int> parents; // Родители вершин (для поиска цикла)
    using Cycle = std::vector<int>; // Тип для представления цикла

public:
    // Конструктор для инициализации графа по заданным вершинам
    Graph(std::vector<std::vector<int>> other_vertices)
            : vertices(std::move(other_vertices)),
              colors(std::vector<Colors>(vertices.size(), White)),
              parents(std::vector<int>(vertices.size() - 1, -1)) {}

    // Рекурсивный DFS для обхода в глубину
    void DFS(int index) {
        colors[index] = Grey; // Помечаем вершину как посещенную
        for (auto& i : vertices[index]) {
            if (colors[i] == White) {
                DFS(i); // Рекурсивно вызываем DFS для смежной вершины
            }
        }
        colors[index] = Black; // Помечаем вершину как завершенную
    }

    // Проверка наличия цикла, используя DFS
    bool IsCycleExist(int index, Cycle& result) {
        colors[index] = Grey; // Помечаем вершину как посещенную
        for (auto& i : vertices[index]) {
            if (colors[i] == Grey) {
                // Нашли обратное ребро, значит есть цикл
                result.push_back(i);
                result.push_back(index);
                return true;
            }
            if (colors[i] == White) {
                parents[i] = index; // Запоминаем предка для вершины i
                if (IsCycleExist(i, result)) {
                    return true;
                }
            }
        }
        colors[index] = Black; // Помечаем вершину как завершенную
        return false;
    }

    // Рекурсивный DFS для топологической сортировки
    bool TopSortDFS(int index, std::vector<int>& answer) {
        colors[index] = Grey; // Помечаем вершину как посещенную
        for (auto& i : vertices[index]) {
            if (colors[i] == Grey) {
                return true; // Нашли цикл
            }
            if (colors[i] == White) {
                if (TopSortDFS(i, answer)) {
                    return true;
                }
            }
        }
        answer.push_back(index); // Добавляем вершину в топологический порядок
        colors[index] = Black; // Помечаем вершину как завершенную
        return false;
    }

    // Выполнение топологической сортировки графа
    std::vector<int> TopSort() {
        std::vector<int> answer;
        for (int i = 0; i < static_cast<int>(vertices.size()); i++) {
            if (colors[i] == White) {
                if (TopSortDFS(i, answer)) {
                    throw CycleExist(); // Если найден цикл, бросаем исключение
                }
            }
        }
        return {answer.rbegin(), answer.rend()}; // Возвращаем топологический порядок
    }

    // Поиск цикла в графе
    Cycle FindCycle() {
        Cycle result;
        for (int i = 0; i < vertices.size(); i++) {
            if (colors[i] == White) {
                if (IsCycleExist(i, result)) {
                    break; // Если найден цикл, останавливаемся
                }
            }
        }
        if (result.empty()) {
            throw NoCycle(); // Если цикл не найден, бросаем исключение
        }
        // Восстанавливаем цикл
        for (int start = parents[result.back()]; parents.back() != result.front();
             start = parents[start]) {
            result.push_back(start);
        }
        return {result.rbegin(), result.rend() - 1}; // Возвращаем цикл
    }

    // Обход всех компонент связности графа
    void DFSAll() {
        for (int i = 0; i < vertices.size(); i++) {
            if (colors[i] == White) {
                DFS(i);
            }
        }
    }

    // Подсчет количества компонент связности графа (прямой)
    int ComponentCounter() {
        int count = 0;
        for (int i = 0; i < vertices.size(); i++) {
            if (colors[i] == White) {
                count++;
                DFS(i);
            }
        }
        return count;
    }
};

// Точка входа в программу
int main() {
    // Создаем объект класса Graph с заданными вершинами и ребрами
    Graph graph({{1, 3}, {}, {1}, {2}});

    // Выполняем топологическую сортировку и выводим результат
    std::vector<int> top_sorted = graph.TopSort();
    for (auto i : top_sorted) {
        std::cout << i << " ";
    }

    return 0; // Выход из программы
}
