#include <cstring>
#include <iostream>

struct Node {
  int _val;
  Node* _next = nullptr;
};

struct Queue {
  Node* _head = nullptr;
  Node* _tail = nullptr;
  size_t _size = 0;

  size_t Size() {
    return _size;
  }

  void Push(int val) {
    Node* node = new Node{val, nullptr};
    if (!Size()) {
      _head = node;
    }
    _tail->_next = node;
    _tail = node;
    _size++;
  }

  void Pop() {
    if (!Size()) {
      return;
    }
    Node* save = _head->_next;
    delete _head;
    _head = save;
    _size--;
  }

  void Front() {
    if (!Size()) {
      return;
    }
    std::cout << _head->_val << '\n';
  }

  void Clear() {
    while (Size()) {
      Pop();
    }
  }
};

int main() {
  size_t n;
  std::cin >> n;
  char str[6];
  Queue queue;
  for (size_t i = 0; i < n; i++) {
    std::cin >> str;
    if (!strcmp(str, "push")) {
      int val;
      std::cin >> val;
      queue.Push(val);
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "pop")) {
      queue.Front();
      queue.Pop();
    } else if (!strcmp(str, "front")) {
      queue.Front();
    } else if (!strcmp(str, "size")) {
      std::cout << queue.Size() << '\n';
    } else if (!strcmp(str, "clear")) {
      queue.Clear();
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "exit")) {
      queue.Clear();
      std::cout << "bye" << '\n';
      break;
    }
  }
  queue.Clear();
}