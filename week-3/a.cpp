#include <iostream>
#include <vector>

// Перечисление цветов для вершин графа
enum Colors { White, Grey, Blue, Red };

class Graph {
private:
    std::vector<std::vector<int>> vertices_; // Список смежности для представления графа
    std::vector<Colors> colors_; // Вектор цветов для вершин графа

public:
    // Конструктор графа, который принимает количество вершин n и количество ребер m
    explicit Graph(int n, int m) {
        vertices_.resize(n); // Изменяем размер списка смежности до n вершин
        colors_.resize(n, White); // Инициализируем все вершины белым цветом
        for (int i = 0; i < m; i++) {
            int src = 0;
            int desc = 0;
            std::cin >> src >> desc; // Вводим ребра
            vertices_[--src].push_back(--desc); // Уменьшаем индексы на 1 и добавляем ребро
            vertices_[desc].push_back(src); // Добавляем обратное ребро для неориентированного графа
        }
    }

    // Рекурсивная функция для проверки, является ли граф двудольным
    bool IsBipartite(int index, int count) {
        bool result = true;
        colors_[index] = Grey; // Временный цвет для текущей вершины
        count++;
        for (auto &i : vertices_[index]) {
            if (colors_[i] == White) {
                result = result && IsBipartite(i, count); // Рекурсивный вызов для смежной вершины
            } else if (colors_[i] == (!(count % 2) ? Blue : Red)) {
                return false; // Возвращаем false, если цвет смежной вершины не соответствует ожидаемому
            }
        }
        count--;
        colors_[index] = (count % 2 ? Blue : Red); // Назначаем цвет текущей вершине в зависимости от глубины рекурсии
        return result;
    }

    // Проверка всех компонент связности графа на двудольность
    bool IsBipartiteAll() {
        bool result = true;
        for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
            if (colors_[i] == White) {
                result = result && IsBipartite(i, 0); // Проверка каждой компоненты связности
            }
        }
        return result;
    }
};

int main() {
    std::ios::sync_with_stdio(false); // Ускорение ввода-вывода
    std::cin.tie(nullptr); // Отключение привязки cin к cout
    std::cout.tie(nullptr); // Отключение привязки cout к cin
    int n = 0;
    int m = 0;
    std::cin >> n >> m; // Ввод количества вершин и ребер
    Graph graph(n, m); // Создание графа
    std::cout << (graph.IsBipartiteAll() ? "YES" : "NO"); // Вывод результата проверки на двудольность
    return 0;
}
