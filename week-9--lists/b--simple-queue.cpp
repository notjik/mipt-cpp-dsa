#include <cstring>
#include <iostream>

struct Node {
  int _val;
  Node* _next;
};

struct Queue {
  Node* _head = nullptr;
  Node* _tail = nullptr;
  size_t _size = 0;

  [[nodiscard]] size_t Size() const {
    return _size;
  }

  void Push(int key) {
    auto* node = new Node{key, nullptr};
    if (_size == 0) {
      _head = _tail = node;
      _size++;
      return;
    }
    _tail->_next = node;
    _tail = node;
    _size++;
  }

  void Pop() {
    if (!Size()) {
      return;
    }
    Node* node = _head;
    _head = node->_next;
    delete node;
    if (_head == nullptr) {
      _tail = nullptr;
    }
    _size--;
  }

  void Front() const {
    if (!Size()) {
      return;
    }
    std::cout << _head->_val << "\n";
  }

  void Clear() {
    while (Size()) {
      Pop();
    }
  }
};

int main() {
  int n;
  std::cin >> n;
  char str[6];
  Queue queue;
  for (int i = 0; i < n; i++) {
    std::cin >> str;
    if (strcmp(str, "pop") == 0) {
      queue.Front();
      queue.Pop();
    } else if (strcmp(str, "push") == 0) {
      int key;
      std::cin >> key;
      queue.Push(key);
      std::cout << "ok" << '\n';
    } else if (strcmp(str, "front") == 0) {
      queue.Front();
    } else if (strcmp(str, "size") == 0) {
      std::cout << queue.Size() << '\n';
    } else if (strcmp(str, "clear") == 0) {
      queue.Clear();
      std::cout << "ok" << '\n';
    } else if (strcmp(str, "exit") == 0) {
      std::cout << "bye" << '\n';
      queue.Clear();
      break;
    }
  }
  queue.Clear();
  return 0;
}
