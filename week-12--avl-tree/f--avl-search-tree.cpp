/*
# F. AVL дерево поиска [cloned]

Ограничение времени: 1 секунда
Ограничение памяти: 64.8 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt

## Декартово дерево поиска

Реализуйте декартово бинарное дерево поиска.

А именно реализуйте следующие методы:

- `get_min()` -- вернуть наименьший элемент дерева.
- `get_max()` -- вернуть наибольший элемент дерева.
- `find(elem)` -- вернуть TRUE, если такой элемент имеется в дереве и FALSE иначе.
- `push(elem)` -- добавить новый элемент в дерево
- `pop(elem)` -- удалить элемент из дерева.

## Формат ввода

На первой строчке число N -- количество запросов к дереву.

На следующих строчках вводятся команды вида `push 5` -- что означает вызвать метод `push(5)`.

## Формат вывода

Для команд `get_min()`, `get_max()` -- вывести ответ на экран.

Для команды `find(elem)` -- вывести TRUE или FALSE на экран.

## Пример

Ввод:
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
Вывод:
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

struct Node {
  int val;
  int height;
  Node* left;
  Node* right;

  explicit Node(int key) : val(key), height(1), left(nullptr), right(nullptr) {};
};

class AVL {
 private:
  Node* LeftRotate(Node* node);
  Node* RightRotate(Node* node);
  int BFactor(Node* node);
  void FixHeight(Node* node);
  int Height(Node* node);
  Node* Balance(Node* node);
  Node* FindMinBackend(Node* node);
  Node* DelMin(Node* node);
  Node* FindMaxBackend(Node* node);
  Node* FindBackend(Node* node, int& key);

 public:
  Node* Insert(Node* node, int key);
  Node* Remove(Node* node, int key);
  void Inorder(Node* node);
  void Delete(Node* node);
  int FindMin(Node* node);
  int FindMax(Node* node);
  bool Find(Node* node, int key);
};

int AVL::Height(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

int AVL::BFactor(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return Height(node->right) - Height(node->left);
}

void AVL::FixHeight(Node* node) {
  int height_left = Height(node->left);
  int height_right = Height(node->right);
  node->height = std::max(height_left, height_right) + 1;
}

Node* AVL::LeftRotate(Node* node) {
  Node* next = node->right->left;
  Node* perv = node->right;
  perv->left = node;
  node->right = next;
  FixHeight(node);
  FixHeight(perv);
  return perv;
}
Node* AVL::RightRotate(Node* node) {
  Node* next = node->left->right;
  Node* perv = node->left;
  perv->right = node;
  node->left = next;
  FixHeight(node);
  FixHeight(perv);
  return perv;
}

Node* AVL::Balance(Node* node) {
  FixHeight(node);
  if (BFactor(node) == -2) {
    if (BFactor(node->left) > 0) {
      node->left = LeftRotate(node->left);
    }
    return RightRotate(node);
  }
  if (BFactor(node) == 2) {
    if (BFactor(node->right) < 0) {
      node->right = RightRotate(node->right);
    }
    return LeftRotate(node);
  }
  return node;
}

Node* AVL::Insert(Node* node, int key) {
  if (node == nullptr) {
    return new Node(key);
  }
  if (node->val > key) {
    node->left = Insert(node->left, key);
  }
  if (node->val < key) {
    node->right = Insert(node->right, key);
  }
  return Balance(node);
}

void AVL::Inorder(Node* node) {
  if (node != nullptr) {
    Inorder(node->left);
    std::cout << node->val << '\n';
    Inorder(node->right);
  }
}

Node* AVL::FindBackend(Node* node, int& key) {
  if (node == nullptr || node->val == key) {
    return node;
  }
  if (key > node->val) {
    return FindBackend(node->right, key);
  }
  if (key < node->val) {
    return FindBackend(node->left, key);
  }
  return nullptr;
}

Node* AVL::FindMinBackend(Node* node) {
  if (node == nullptr || node->left == nullptr) {
    return node;
  }
  return FindMinBackend(node->left);
}

Node* AVL::FindMaxBackend(Node* node) {
  if (node == nullptr || node->right == nullptr) {
    return node;
  }
  return FindMaxBackend(node->right);
}

Node* AVL::DelMin(Node* node) {
  if (node->left == nullptr) {
    return node->right;
  }
  node->left = DelMin(node->left);
  return Balance(node);
}

Node* AVL::Remove(Node* node, int key) {
  if (!node) {
    return nullptr;
  }
  if (node->val > key) {
    node->left = Remove(node->left, key);
  } else if (node->val < key) {
    node->right = Remove(node->right, key);
  } else {
    Node* right = node->right;
    Node* left = node->left;
    delete node;
    if (!right) {
      return left;
    }
    Node* min = FindMinBackend(right);
    min->right = DelMin(right);
    min->left = left;
    return Balance(min);
  }
  return Balance(node);
}

bool AVL::Find(Node* node, int key) {
  return FindBackend(node, key);
}

int AVL::FindMin(Node* node) {
  Node* find = FindMinBackend(node);
  return (find ? find->val : INT_MAX);
}

int AVL::FindMax(Node* node) {
  Node* find = FindMaxBackend(node);
  return (find ? find->val : INT_MIN);
}

void AVL::Delete(Node* node) {
  if (node != nullptr) {
    Delete(node->left);
    Delete(node->right);
    delete node;
  }
}

int main() {
  Node* root = nullptr;
  AVL avl;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    char input[8];
    std::cin >> input;
    if (!strcmp(input, "get_min")) {
      int min = avl.FindMin(root);
      if (min != INT_MAX) {
        std::cout << min << '\n';
      }
    } else if (!strcmp(input, "get_max")) {
      int max = avl.FindMax(root);
      if (max != INT_MIN) {
        std::cout << max << '\n';
      }
    } else if (!strcmp(input, "find")) {
      int num;
      std::cin >> num;
      std::cout << (avl.Find(root, num) ? "TRUE" : "FALSE") << '\n';
    } else if (!strcmp(input, "push")) {
      int num;
      std::cin >> num;
      root = avl.Insert(root, num);
    } else if (!strcmp(input, "pop")) {
      int num;
      std::cin >> num;
      root = avl.Remove(root, num);
    }
  }
  avl.Delete(root);
  return 0;
}