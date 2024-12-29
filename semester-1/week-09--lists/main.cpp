#include <iostream>

struct Node {
  int val;
  Node* next = nullptr;
};

struct List {
  Node* first = nullptr;
  Node* last = nullptr;

  bool IsEmpty() {
    return first == nullptr;
  }

  void PushBack(int _val) {
    Node* node = new Node{_val};
    if (IsEmpty()) {
      first = node;
    } else {
      last->next = node;
    }
    last = node;
  }

  void Print() {
    Node* runner = first;
    while (runner) {
      std::cout << runner->val << ' ';
      runner = runner->next;
    }
  }

  void PopFirst() {
    if (IsEmpty()) {
      return;
    }
    Node* new_root = first->next;
    if (first == last) {
      last = new_root;
    }
    delete first;
    first = new_root;
  }

  void PopLast() {
    if (IsEmpty()) {
      return;
    }
    if (first == last) {
      PopFirst();
      return;
    }
    Node* runner = first;
    while (runner->next != last) {
      runner = runner->next;
    }
    delete runner->next;
    last = runner;
    runner->next = nullptr;
  }

  void Pop(int _val) {
    if (IsEmpty()) {
      return;
    }
    if (first->val == _val) {
      PopFirst();
      return;
    }
    if (last->val == _val) {
      PopLast();
      return;
    }
    Node* runner = first;
    Node* runner_next = first->next;
    while (runner_next != nullptr && runner_next->val != _val) {
      runner = runner->next;
      runner_next = runner_next->next;
    }
    runner->next = runner_next->next;
    delete runner_next;
  }

  void Clear() {
    while (!IsEmpty()) {
      PopLast();
    }
  }

  Node* Find(int _val) {
    Node* runner = first;
    while (runner && runner->val != _val) {
      runner = runner->next;
    }
    return runner;
  }

  Node* operator[](const int index) {
    Node* node = first;
    for (int i = 0; i < index; i++) {
      if (!node) {
        return nullptr;
      }
      node = node->next;
    }
    return node;
  }
};




int main() {
  return 0;
}