#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Graph {
private:
    std::vector<std::vector<int>> vertices_; // Список смежности для хранения графа
    std::vector<Colors> colors_; // Цвета вершин (White, Grey, Black)

public:
    // Конструктор графа, принимающий количество вершин n
    explicit Graph(int n) {
        vertices_.resize(n); // Изменяем размер списка смежности до n элементов
        colors_.resize(n, White); // Инициализируем все вершины белым цветом
        for (int i = 0; i < n; i++) {
            int desc = 0;
            std::cin >> desc; // Вводим номера вершин, с которыми связана текущая вершина
            vertices_[i].push_back(--desc); // Добавляем ребро от текущей вершины к desc в список смежности
            vertices_[desc].push_back(i); // Добавляем обратное ребро для неориентированного графа
        }
    }

    // Рекурсивная функция обхода графа в глубину (DFS)
    void DFS(int index) {
        colors_[index] = Grey; // Помечаем текущую вершину как серую (в процессе обхода)
        for (auto &i : vertices_[index]) {
            if (colors_[i] == White) { // Если смежная вершина белая, рекурсивно вызываем DFS для нее
                DFS(i);
            }
        }
        colors_[index] = Black; // Помечаем текущую вершину как черную (обход завершен)
    }

    // Функция для подсчета компонент связности графа
    int ComponentCounter() {
        int count = 0; // Счетчик компонент связности
        for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
            if (colors_[i] == White) { // Если вершина белая, значит, она начало новой компоненты
                count++; // Увеличиваем счетчик компонент
                DFS(i); // Запускаем DFS для текущей вершины, чтобы пометить всю компоненту
            }
        }
        return count; // Возвращаем количество компонент связности
    }
};

int main() {
    std::ios::sync_with_stdio(false); // Ускорение ввода-вывода
    std::cin.tie(nullptr); // Отключение привязки cin к cout
    std::cout.tie(nullptr); // Отключение привязки cout к cin
    int n = 0;
    std::cin >> n; // Ввод количества вершин
    Graph graph(n); // Создание объекта графа
    std::cout << graph.ComponentCounter(); // Вывод количества компонент связности
    return 0;
}
