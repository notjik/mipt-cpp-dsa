#include <climits>
#include <iostream>
#include <vector>

// Класс, представляющий ребро в графе
class Edge {
public:
    int begin;    // Начальная вершина ребра
    int end;      // Конечная вершина ребра
    int weight;   // Вес (длина) ребра

    // Конструктор для инициализации ребра
    Edge(int src, int dest, int w) : begin(src), end(dest), weight(w) {
    }

    // Перегрузка оператора < для сравнения ребер по весу
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Класс, представляющий систему непересекающихся множеств (СНМ)
class CDU {
public:
    int Kraskal();   // Метод для выполнения алгоритма Краскала
    friend std::istream& operator>>(std::istream& is, CDU& cdu);   // Перегрузка оператора >> для ввода графа

private:
    std::vector<int> parent_;   // Родительская вершина для каждой вершины (СНМ)
    std::vector<Edge> edges_;   // Вектор ребер графа
    std::vector<int> rank_;     // Ранги для оптимизации объединения множеств

    int FindSet(int idx);   // Метод для нахождения корня множества
    void Union(int first, int second);   // Метод для объединения двух множеств
};

// Перегрузка оператора >> для ввода графа
std::istream& operator>>(std::istream& is, CDU& cdu) {
    int n = 0;
    int m = 0;
    is >> n >> m;   // Чтение числа вершин (n) и ребер (m)
    cdu.parent_.resize(n, -1);   // Инициализация массива родительских вершин
    cdu.rank_.resize(n, 1);      // Инициализация массива рангов вершин

    // Чтение каждого ребра и добавление его в вектор ребер
    for (int i = 0; i < m; i++) {
        int begin = 0;
        int end = 0;
        int weight = 0;
        is >> begin >> end >> weight;   // Чтение начальной вершины, конечной вершины и веса ребра
        begin--;   // Приведение индексов к нумерации с нуля
        end--;     // Приведение индексов к нумерации с нуля

        Edge edge = Edge(begin, end, weight);   // Создание ребра
        cdu.edges_.push_back(edge);            // Добавление ребра в вектор ребер
    }
    return is;
}

// Метод для нахождения корня множества с использованием эвристики сжатия пути
int CDU::FindSet(int idx) {
    if (parent_[idx] == -1) {   // Если вершина является корнем
        return idx;               // Возвращаем ее индекс
    }
    return parent_[idx] = FindSet(parent_[idx]);   // Иначе находим и обновляем корень рекурсивно
}

// Метод для объединения двух множеств с использованием эвристики сжатия пути и объединения по рангу
void CDU::Union(int first, int second) {
    int leader_first = FindSet(first);    // Находим корень первого множества
    int leader_second = FindSet(second);  // Находим корень второго множества

    if (rank_[leader_first] > rank_[leader_second]) {
        parent_[leader_second] = leader_first;   // Присоединяем второе множество к первому
    } else if (rank_[leader_first] < rank_[leader_second]) {
        parent_[leader_first] = leader_second;   // Присоединяем первое множество ко второму
    } else {
        parent_[leader_second] = leader_first;   // Присоединяем второе множество к первому
        rank_[leader_first]++;                   // Увеличиваем ранг первого множества
    }
}

// Метод для выполнения алгоритма Краскала на графе
int CDU::Kraskal() {
    int weight = 0;   // Переменная для хранения веса минимального остовного дерева
    for (auto& edge : edges_) {   // Проходим по всем ребрам графа
        if (FindSet(edge.begin) != FindSet(edge.end)) {   // Если ребро соединяет различные множества
            Union(edge.begin, edge.end);   // Объединяем эти множества
            weight += edge.weight;         // Добавляем вес ребра к общему весу остовного дерева
        }
    }
    return weight;   // Возвращаем общий вес минимального остовного дерева
}

// Основная функция для чтения входных данных, создания графа и выполнения алгоритма Краскала
int main() {
    std::cin.tie(nullptr);   // Отключение синхронизации с stdio
    std::cout.tie(nullptr);  // Отключение синхронизации с stdio
    std::istream::sync_with_stdio(false);  // Отключение синхронизации с stdio

    CDU cdu;   // Создание экземпляра класса CDU (Краскал)
    std::cin >> cdu;   // Чтение входных данных графа
    std::cout << cdu.Kraskal();   // Вывод веса минимального остовного дерева, найденного алгоритмом Краскала

    return 0;   // Выход из функции main
}
