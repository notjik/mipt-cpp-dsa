#include <iostream>
#include <cstdint>
#include <string>
#include <utility>

struct Node {
  std::string elem;
};

class HashTable {
 private:
  Node **_table;
  size_t _size;

 public:
  explicit HashTable(size_t size) {
    _table = new Node *[size]{nullptr};
    _size = size;
  }
  ~HashTable() {
    for (size_t i = 0; i < _size; i++) {
      if (_table[i]) {
        delete _table[i];
      }
    }
    delete[] _table;
  }
  void Add(uint64_t number, std::string name) {
    _table[number] = new Node();
    _table[number]->elem = std::move(name);
  }
  void Del(uint64_t number) {
    _table[number] = nullptr;
  };
  void Find(uint64_t number) {
    std::cout << (!_table[number] ? "not found" : _table[number]->elem) << '\n';
  }
};

int main() {
  HashTable hash_table(static_cast<size_t>(1e7));
  int n;
  std::cin >> n;
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