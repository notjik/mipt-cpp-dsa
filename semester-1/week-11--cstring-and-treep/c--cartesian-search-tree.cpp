/*
# Задача C. Декартово дерево поиска

**Ограничение времени**: 1 секунда
**Ограничение памяти**: 64.8 Мб
**Ввод**: стандартный ввод или input.txt
**Вывод**: стандартный вывод или output.txt

Реализуйте декартово бинарное дерево поиска.

А именно реализуйте следующие методы:

1. `get_min()` -- вернуть наименьший элемент дерева.
2. `get_max()` -- вернуть наибольший элемент дерева.
3. `find(elem)` -- вернуть TRUE, если такой элемент имеется в дереве и FALSE иначе.
4. `push(elem)` -- добавить новый элемент в дерево
5. `pop(elem)` -- удалить элемент из дерева.

## Формат ввода

На первой строчке число N -- количество запросов к дереву.

На следующих строчках вводятся команды вида `push 5` -- что означает вызвать метод `push(5)`

## Формат вывода

Для команд `get_min()`, `get_max()` -- вывести ответ на экран.

Для команды `find(elem)` -- вывести TRUE или FASLE на экран.

## Пример

### Ввод
```
10
pop 3
push 4
push 6
pop 4
find 6
push -10
get_max
find 7
push 4
find -5
```
### Вывод
```
TRUE
6
FALSE
FALSE
```
 */
#include <cstring>
#include <climits>
#include <iostream>
#include <random>

struct Node {
  int val;
  int priority;
  Node* left;
  Node* right;

  Node(int key, std::mt19937& gen) : val(key), left(nullptr), right(nullptr) {
    priority = gen();
  }
};

struct Pair {
  Node* left;
  Node* right;
};

class Treap {
 private:
  Node* Merge(Node* left, Node* right);
  Pair Split(Node* root, int key);
  Node* FindMinBackend(Node* root);
  Node* FindMaxBackend(Node* root);
  Node* FindBackend(Node* root, int key);

 public:
  Node* Insert(Node* root, int key, std::mt19937& gen);
  void Print(Node* root);
  void Delete(Node* root);
  Node* Remove(Node* root, int key);
  int FindMin(Node* root);
  int FindMax(Node* root);
  bool Find(Node* root, int key);
};

Node* Treap::Merge(Node* left, Node* right) {
  if (left == nullptr) {
    return right;
  }
  if (right == nullptr) {
    return left;
  }
  if (left->priority > right->priority) {
    left->right = Merge(left->right, right);
    return left;
  }
  right->left = Merge(left, right->left);
  return right;
}

Pair Treap::Split(Node* root, int key) {
  if (root == nullptr) {
    return {nullptr, nullptr};
  }
  if (key > root->val) {
    Pair pair = Split(root->right, key);
    root->right = pair.left;
    return {root, pair.right};
  }
  Pair pair = Split(root->left, key);
  root->left = pair.right;
  return {pair.left, root};
}

Node* Treap::FindBackend(Node* root, int key) {
  if (root == nullptr || key == root->val) {
    return root;
  }
  if (key > root->val) {
    return FindBackend(root->right, key);
  }
  return FindBackend(root->left, key);
}

Node* Treap::FindMinBackend(Node* root) {
  if (root == nullptr || root->left == nullptr) {
    return root;
  }
  return FindMinBackend(root->left);
}

Node* Treap::FindMaxBackend(Node* root) {
  if (root == nullptr || root->right == nullptr) {
    return root;
  }
  return FindMaxBackend(root->right);
}

bool Treap::Find(Node* root, int key) {
  Node* node = FindBackend(root, key);
  if (node == nullptr) {
    return false;
  }
  return node->val == key;
}

int Treap::FindMin(Node* root) {
  Node* node = FindMinBackend(root);
  return (node != nullptr ? node->val : INT_MAX);
}

int Treap::FindMax(Node* root) {
  Node* node = FindMaxBackend(root);
  return (node != nullptr ? node->val : INT_MIN);
}

Node* Treap::Insert(Node* root, int key, std::mt19937& gen) {
  if (Find(root, key)) {
    return root;
  }
  Pair q = Split(root, key);
  auto* node = new Node(key, gen);
  Node* tmp = Merge(q.left, node);
  return Merge(tmp, q.right);
}

void Treap::Print(Node* root) {
  if (root != nullptr) {
    Print(root->left);
    std::cout << root->val << " " << root->priority << '\n';
    Print(root->right);
  }
}

void Treap::Delete(Node* root) {
  if (root != nullptr) {
    Delete(root->left);
    Delete(root->right);
    delete root;
  }
}

Node* Treap::Remove(Node* root, int key) {
  if (root == nullptr) {
    return nullptr;
  }
  if (key == root->val) {
    Node* new_root = Merge(root->left, root->right);
    delete root;
    return new_root;
  }
  if (key > root->val) {
    root->right = Remove(root->right, key);
  } else {
    root->left = Remove(root->left, key);
  }
  return root;
}

int main() {
  Treap treap;
  Node* root = nullptr;
  std::mt19937 gen;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    char input[8];
    std::cin >> input;
    if (!strcmp(input, "get_min")) {
      int min = treap.FindMin(root);
      if (min != INT_MAX) {
        std::cout << min << '\n';
      }
    } else if (!strcmp(input, "get_max")) {
      int max = treap.FindMax(root);
      if (max != INT_MIN) {
        std::cout << max << '\n';
      }
    } else if (!strcmp(input, "find")) {
      int num;
      std::cin >> num;
      std::cout << (treap.Find(root, num) ? "TRUE" : "FALSE") << '\n';
    } else if (!strcmp(input, "push")) {
      int num;
      std::cin >> num;
      root = treap.Insert(root, num, gen);
    } else if (!strcmp(input, "pop")) {
      int num;
      std::cin >> num;
      root = treap.Remove(root, num);
    } else if (!strcmp(input, "print")) {
      treap.Print(root);
    }
  }
  treap.Delete(root);
  return 0;
}