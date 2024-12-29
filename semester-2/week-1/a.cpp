#include <iostream>
#include <cstdint>
#include <string>
#include <utility>

// Структура Node, которая хранит строку elem
struct Node {
    std::string elem;
};

// Класс HashTable для работы с хеш-таблицей
class HashTable {
private:
    Node **_table;  // Указатель на массив указателей на Node
    size_t _size;   // Размер хеш-таблицы

public:
    // Конструктор HashTable, который выделяет память под таблицу
    explicit HashTable(size_t size) {
        _table = new Node *[size]{nullptr};
        _size = size;
    }

    // Деструктор HashTable, который освобождает выделенную память
    ~HashTable() {
        for (size_t i = 0; i < _size; i++) {
            if (_table[i]) {
                delete _table[i];
            }
        }
        delete[] _table;
    }

    // Метод для добавления нового элемента в таблицу
    void Add(uint64_t number, std::string name) {
        _table[number] = new Node();
        _table[number]->elem = std::move(name);
    }

    // Метод для удаления элемента из таблицы
    void Del(uint64_t number) {
        _table[number] = nullptr;
    }

    // Метод для поиска элемента в таблице
    void Find(uint64_t number) {
        std::cout << (!_table[number] ? "not found" : _table[number]->elem) << '\n';
    }
};

int main() {
    // Создание хеш-таблицы с размером 1e7
    HashTable hash_table(static_cast<size_t>(1e7));
    int n;  // Количество команд
    std::cin >> n;

    // Выполнение команд
    for (int i = 0; i < n; i++) {
        std::string command;
        std::cin >> command;
        if (command == "add") {
            uint64_t number;
            std::string name;
            std::cin >> number;
            std::cin >> name;
            hash_table.Add(number, name);
        } else if (command == "del") {
            uint64_t number;
            std::cin >> number;
            hash_table.Del(number);
        } else if (command == "find") {
            uint64_t number;
            std::cin >> number;
            hash_table.Find(number);
        }
    }

    return 0;
}
