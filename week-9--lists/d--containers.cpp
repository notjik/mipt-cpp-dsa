#include <climits>
#include <iostream>

struct Node {
  int _val;
  Node* _next = nullptr;
};

struct Stack {
  Node* _head = nullptr;
  size_t _size = 0;

  [[nodiscard]] size_t Size() const {
    return _size;
  }

  void Push(int val) {
    auto* node = new Node{val, _head};
    _head = node;
    _size++;
  }

  int Pop() {
    if (!Size()) {
      return INT_MIN;
    }
    Node* save = _head->_next;
    delete _head;
    _head = save;
    _size--;
    return save->_val;
  }

  [[nodiscard]] int Back() const {
    if (!Size()) {
      return INT_MIN;
    }
    return _head->_val;
  }

  void Clear() {
    while (Size()) {
      Pop();
    }
  }
};

int AllIsKey(Stack* stack, int key){
  Node* runner = stack->_head;
  if (runner == nullptr) {
    return
  }
  while (runner != nullptr)
}

int main() {
  int n;
  std::cin >> n;
  auto** containers = new Stack*[n];
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; j++) {
      int val = 0;
      std::cin >> val;
      containers[n]->Push(val);
    }
  }
  for (int i = 0; i < n; i++) {
    int val = containers[i]->Pop();
    if (i != val - 1) {
      containers[i]->Push(val);
      std::cout << i + 1 << ' ' << val << '\n';
    } else {
      containers[(i + 1) % n]->Push(val);
      std::cout << ((i + 1) % n) + 1 << ' ' << val << '\n';
    }
  }
  return 0;
}
