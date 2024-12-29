#include <iostream>
#include <string>
#include <cstdint>

// Шаблонный класс PolynomialHash для вычисления хеша полиномиальным методом
template <int64_t X>
class PolynomialHash {
private:
    const int64_t p_ = 1e9 + 7;  // Большое простое число
    int64_t x_ = X;              // Константа для полиномиального хеша

public:
    // Перегрузка оператора () для вычисления хеша строки
    int64_t operator()(const std::string& key, int64_t size) const {
        int64_t hash = 0;
        int64_t pow = 1;
        for (char i : key) {
            hash = ((i * pow) % p_ + hash) % p_;
            pow = (pow * x_) % p_;
        }
        return hash % size;
    }
};

// Структура Node для хранения узлов в хеш-таблице
struct Node {
    std::string key_;

    explicit Node(std::string key) : key_(std::move(key)) {
    }
};

// Класс HashTable для реализации хеш-таблицы с двойным хешированием
class HashTable {
private:
    PolynomialHash<263> hash1_;  // Первый хеш-функция
    PolynomialHash<52> hash2_;   // Второй хеш-функция
    int64_t size_;               // Размер хеш-таблицы
    Node** buckets_;             // Массив указателей на узлы

    // Метод для получения индекса хеша с учетом двойного хеширования
    int64_t GetHashIndex(const std::string& value) {
        int64_t idx = hash1_(value, size_);
        int64_t step = hash2_(value, size_);
        int i = 0;
        while (buckets_[i] != nullptr) {
            idx = (idx + (i * step) % size_) % size_;
            ++i;
        }

        return idx;
    }

public:
    // Конструктор хеш-таблицы
    explicit HashTable(int64_t size) : size_(size) {
        buckets_ = new Node* [size_] { nullptr };
    }

    // Деструктор хеш-таблицы
    ~HashTable() {
        for (int64_t i = 0; i < size_; ++i) {
            delete buckets_[i];
        }
        delete[] buckets_;
    }

    // Метод для поиска элемента в таблице
    bool Find(const std::string& value) {
        return buckets_[GetHashIndex(value)] != nullptr;
    }

    // Метод для добавления элемента в таблицу
    void Push(const std::string& value) {
        int64_t idx = GetHashIndex(value);
        if (buckets_[idx]) {
            buckets_[idx]->key_ = value;
        } else {
            buckets_[idx] = new Node(value);
        }
    }

    // Метод для удаления элемента из таблицы
    bool Pop(const std::string& value) {
        int64_t idx = GetHashIndex(value);
        if (!buckets_[idx]) {
            return false;
        }
        delete buckets_[idx];
        buckets_[idx] = nullptr;
        return true;
    }
};

int main() {
    int n = 0;  // Количество команд
    std::cin >> n;

    HashTable table(1e6);  // Создание хеш-таблицы размером 1e6

    std::string command;
    std::string key;

    // Обработка команд
    while (n--) {
        std::cin >> command;
        if (command == "push") {
            std::cin >> key;
            table.Push(key);
        } else if (command == "pop") {
            std::cin >> key;
            std::cout << (table.Pop(key) ? "TRUE" : "FALSE") << std::endl;
        } else if (command == "search") {
            std::cin >> key;
            std::cout << (table.Find(key) ? "TRUE" : "FALSE") << std::endl;
        }
    }

    return 0;
}
