/*
# Задача E: Частоты появления элементов

**Ограничение времени**: 2 секунды
**Ограничение памяти**: 256Mb
**Ввод**: стандартный ввод или input.txt
**Вывод**: стандартный вывод или output.txt

## Условие
По данной последовательности постройте дерево, запоминая для каждого элемента его значение и количество его повторений в последовательности.

## Формат ввода
Вводится последовательность целых чисел, заканчивающаяся нулем. Сам ноль в последовательность не входит.

## Формат вывода
Выведите на экран содержимое дерева в порядке возрастания, по одному элементу на строку. В каждой строке выводите значение элемента, затем, через пробел, укажите, сколько раз он встречается в исходной последовательности.

## Пример
**Ввод**
```
7 3 2 1 9 5 4 6 8 0
```
**Вывод**
```
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
```
 */
#include <iostream>

struct Node {
  int val;
  int count;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

Node* Search(Node* root, int key) {
  if (root == nullptr || key == root->val) {
    return root;
  }
  if (key > root->val) {
    return Search(root->right, key);
  }
  return Search(root->left, key);
}

Node* FindBackend(Node* root, int key) {
  if (root == nullptr || key == root->val) {
    return root;
  }
  if (key > root->val) {
    return Search(root->right, key);
  }
  return Search(root->left, key);
}

void InsertImpl(Node* root, Node* node) {
  if (root == nullptr) {
    root = node;
    return;
  }
  if (root->val > node->val) {
    if (root->left == nullptr) {
      root->left = node;
      node->parent = root;
      return;
    }
    InsertImpl(root->left, node);
  } else {
    if (root->right == nullptr) {
      root->right = node;
      node->parent = root;
      return;
    }
    InsertImpl(root->right, node);
  }
}

void Insert(Node* root, int val) {
  Node* pre_insert = Search(root, val);
  if (pre_insert) {
    pre_insert->count++;
    return;
  }
  auto* node = new Node;
  node->val = val;
  node->count = 1;
  InsertImpl(root, node);
}

Node* Max(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  while (root->right != nullptr) {
    root = root->right;
  }
  return root;
}

Node* MaxRecursive(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->right == nullptr) {
    return root;
  }
  return MaxRecursive(root->right);
}

Node* Min(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  while (root->left != nullptr) {
    root = root->left;
  }
  return root;
}

Node* MinRecursive(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->left == nullptr) {
    return root;
  }
  return MaxRecursive(root->left);
}

void Erase(Node* node) {
  Node* parent = node->parent;
  if (node->left == nullptr && node->right == nullptr) {
    if (parent->left == node) {
      parent->left = nullptr;
    }
    if (parent->right == node) {
      parent->right = nullptr;
    }
    delete node;
  } else if (node->left == nullptr || node->right == nullptr) {
    if (node->left == nullptr) {
      if (parent->left == node) {
        parent->left = node->right;
      } else {
        parent->right = node->right;
      }
      node->right->parent = parent;
    } else {
      if (parent->right == node) {
        parent->right = node->left;
      } else {
        parent->left = node->left;
      }
      node->left->parent = parent;
    }
    delete node;
  }
}

void Erase(Node* root, int key) {
  Erase(Search(root, key));
}

void Clear(Node* root) {
  if (root != nullptr) {
    Clear(root->left);
    Clear(root->right);
    delete root;
  }
}

void InorderWalk(Node* root) {
  if (root != nullptr) {
    InorderWalk(root->left);
    std::cout << root->val << ' ' << root->count << '\n';
    InorderWalk(root->right);
  }
}

void PreorderWalk(Node* root) {
  if (root != nullptr) {
    std::cout << root->val << ' ';
    PreorderWalk(root->left);
    PreorderWalk(root->right);
  }
}

void PostorderWalk(Node* root) {
  if (root != nullptr) {
    PostorderWalk(root->left);
    PostorderWalk(root->right);
    std::cout << root->val << ' ';
  }
}

int main() {
  int num;
  std::cin >> num;
  auto* root = new Node{num, 1};
  while (num != 0) {
    std::cin >> num;
    if (num == 0) {
      break;
    }
    Insert(root, num);
  }
  InorderWalk(root);
  Clear(root);
  return 0;
}