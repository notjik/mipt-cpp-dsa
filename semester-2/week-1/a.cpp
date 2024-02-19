#include <iostream>
#include <cstdint>
#include <string>

class HashTable {
 private:
  std::string _table[static_cast<uint64_t>(10e8)];
 public:
  void Add(uint64_t number, std::string name) {
    _table[number] = std::move(name);
  }
  void Del(uint64_t number) {
    _table[number] = "";
  };
  void Find(uint64_t number) {
  std::cout << (_table[number].empty() ? "not found" : _table[number]) << '\n';
  }
};

int main() {
  HashTable hash_table;
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