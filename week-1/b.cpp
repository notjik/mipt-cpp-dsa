#include <cstdint>
#include <iostream>
#include <string>

// Класс PolynomialHash для вычисления хешей полиномиальным методом
class PolynomialHash {
private:
    const int64_t p_ = 1e9 + 7;  // Большое простое число
    const int64_t x_ = 263;      // Константа для полиномиального хеша
public:
    // Перегрузка оператора () для вычисления хеша строки
    int64_t operator()(const std::string& key, uint64_t size) const {
        int64_t hash = 0;
        int64_t pow = 1;
        for (char i : key) {
            hash = ((i * pow) % p_ + hash) % p_;
            pow = (pow * x_) % p_;
        }
        return hash % size;
    }
};

// Структура Node для хранения узлов в списке
struct Node {
    std::string key_;
    Node* next_ = nullptr;
    Node* prev_ = nullptr;

    // Конструкторы для инициализации узлов
    Node(std::string key, Node* next, Node* prev) : key_(key), next_(next), prev_(prev) {};
    Node(std::string key) : Node(key, nullptr, nullptr) {};
};

// Класс List для реализации двусвязного списка
class List {
private:
    uint64_t size_ = 0;
    Node* top = nullptr;  // Указатель на начало списка
    Node* end = nullptr;  // Указатель на конец списка

public:
    List() {
        top = nullptr;
        end = nullptr;
    };
    ~List() {
        for (Node* node = top; node != end;) {
            Node* last = node;
            node = node->next_;
            delete last;
        }
    }

    // Метод для добавления нового элемента в список
    void Add(const std::string& key) {
        if (!top) {
            top = new Node(key);
            end = top;
        } else {
            top->prev_ = new Node(key);
            top->prev_->next_ = top;
            top = top->prev_;
        }
        ++size_;
    }

    // Метод для удаления элемента из списка
    void Remove(const std::string& key) {
        Node* node = Find(key);
        if (!node) {
            return;
        }
        if (node->prev_ && node->next_) {
            node->prev_->next_ = node->next_;
            node->next_->prev_ = node->prev_;
        } else if (node->prev_) {
            end->prev_->next_ = nullptr;
            end = end->prev_;
        } else if (node->next_) {
            top->next_->prev_ = nullptr;
            top = top->next_;
        } else {
            top = nullptr;
            end = nullptr;
        }

        delete node;
        --size_;
    }

    // Метод для поиска элемента в списке
    Node* Find(const std::string& key) {
        for (Node* node = top; node != nullptr; node = node->next_) {
            if (node->key_ == key) {
                return node;
            }
        }

        return nullptr;
    }

    // Метод для печати элементов списка
    void Print() {
        for (Node* node = top; node != nullptr; node = node->next_) {
            std::cout << node->key_ << (node != end ? " " : "");
        }
        std::cout << std::endl;
    }
};

// Класс HashTable для реализации хеш-таблицы с использованием списка
class HashTable {
private:
    PolynomialHash hash_;  // Объект для вычисления хешей
    uint64_t size_;        // Размер хеш-таблицы
    List* table_;          // Массив списков для хранения данных

public:
    HashTable(uint64_t size) {
        size_ = size;
        table_ = new List[size_];
    }
    ~HashTable() {
        delete[] table_;
    }

    // Метод для поиска элемента в таблице
    bool Find(const std::string& key) {
        return table_[hash_(key, size_)].Find(key);
    }

    // Метод для добавления элемента в таблицу
    void Add(const std::string& key) {
        int64_t idx = hash_(key, size_);
        if (table_[idx].Find(key)) {
            return;
        }
        table_[idx].Add(key);
    }

    // Метод для удаления элемента из таблицы
    void Del(const std::string& key) {
        int64_t idx = hash_(key, size_);
        table_[idx].Remove(key);
    }

    // Метод для печати элементов в конкретной ячейке таблицы
    void Print(int64_t idx) {
        table_[idx % size_].Print();
    }
};

int main() {
    int m, n;  // m - размер таблицы, n - количество команд
    std::cin >> m >> n;
    HashTable table(m);  // Создание хеш-таблицы размером m
    std::string command, key;
    for (int i = 0; i < n; i++) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> key;
            table.Add(key);
        } else if (command == "find") {
            std::cin >> key;
            std::cout << (table.Find(key) ? "yes" : "no") << '\n';
        } else if (command == "del") {
            std::cin >> key;
            table.Del(key);
        } else if (command == "check") {
            int idx;
            std::cin >> idx;
            table.Print(idx);
        }
    }
}
