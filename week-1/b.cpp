#include <cstdint>
#include <iostream>
#include <string>

class PolynomialHash {
 private:
  const int64_t p_ = 1e9 + 7;
  const int64_t x_ = 263;
 public:
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

struct Node {
  std::string key_;
  Node* next_ = nullptr;
  Node* prev_ = nullptr;

  Node(std::string key, Node* next, Node* prev) : key_(key), next_(next), prev_(prev) {};
  Node(std::string key) : Node(key, nullptr, nullptr) {};
};

class List {
 private:
  uint64_t size_ = 0;
  Node* top = nullptr;
  Node* end = nullptr;

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

  Node* Find(const std::string& key) {
    for (Node* node = top; node != nullptr; node = node->next_) {
      if (node->key_ == key) {
        return node;
      }
    }

    return nullptr;
  }

  void Print() {
    for (Node* node = top; node != nullptr; node = node->next_) {
      std::cout << node->key_ << (node != end ? " " : "");
    }
    std::cout << std::endl;
  }
};

class HashTable {
 private:
  PolynomialHash hash_;
  uint64_t size_;
  List* table_;
 public:
  HashTable(uint64_t size) {
    size_ = size;
    table_ = new List[size_];
  }
  ~HashTable() {
    delete[] table_;
  }

  bool Find(const std::string& key) {
    return table_[hash_(key, size_)].Find(key);
  }

  void Add(const std::string& key) {
    int64_t idx = hash_(key, size_);
    if (table_[idx].Find(key)) {
      return;
    }
    table_[idx].Add(key);
  }

  void Del(const std::string& key) {
    int64_t idx = hash_(key, size_);
    table_[idx].Remove(key);
  }

  void Print(int64_t idx) {
    table_[idx % size_].Print();
  }
};

int main() {
  int m, n;
  std::cin >> m >> n;
  HashTable table(m);
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