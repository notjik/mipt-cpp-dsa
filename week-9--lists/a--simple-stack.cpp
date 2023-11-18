#include <cstring>
#include <iostream>

struct Node {
  int _val;
  Node* _next = nullptr;
};

struct Stack {
  Node* _head = nullptr;
  size_t _size = 0;

  size_t Size() {
    return _size;
  }

  void Push(int val) {
    auto* node = new Node{val, _head};
    _head = node;
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

  void Back() {
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
  Stack stack;
  for (size_t i = 0; i < n; i++) {
    std::cin >> str;
    if (!strcmp(str, "push")) {
      int val;
      std::cin >> val;
      stack.Push(val);
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "pop")) {
      stack.Back();
      stack.Pop();
    } else if (!strcmp(str, "back")) {
      stack.Back();
    } else if (!strcmp(str, "size")) {
      std::cout << stack.Size() << '\n';
    } else if (!strcmp(str, "clear")) {
      stack.Clear();
      std::cout << "ok" << '\n';
    } else if (!strcmp(str, "exit")) {
      stack.Clear();
      std::cout << "bye" << '\n';
      break;
    }
  }
  stack.Clear();
}