/*
# Задача C: Сбалансированность

**Ограничение времени**: 1 секунда
**Ограничение памяти**: 128Mb
**Ввод**: стандартный ввод или input.txt
**Вывод**: стандартный вывод или output.txt

## Условие
Дерево называется сбалансированным, если для любой его вершины высота левого и правого поддерева для этой вершины различаются не более чем на 1.

## Формат ввода
Вводится последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит. Постройте дерево, соответствующее данной последовательности.

## Формат вывода
Определите, является ли дерево сбалансированным, выведите слово YES или NO.

## Пример
**Ввод**
```
7 3 2 1 9 5 4 6 8 0
```
**Вывод**
```
YES
```
 */
#include <iostream>

struct Node {
  int val;
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
  if (Search(root, val)) {
    return;
  }
  auto* node = new Node;
  node->val = val;
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
    std::cout << root->val << ' ';
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

int Height(Node* root) {
  if (root == nullptr) {
    return 0;
  }
  return std::max(Height(root->left), Height(root->right)) + 1;
}

void BFactor(Node* root, bool& result) {
  if (root != nullptr) {
    BFactor(root->left, result);
    if (abs(Height(root->left) - Height(root->right)) > 2) {
      result = false;
      return;
    }
    BFactor(root->right, result);
  }
}

int main() {
  int num;
  std::cin >> num;
  auto* root = new Node{num};
  while (num != 0) {
    std::cin >> num;
    if (num == 0) {
      break;
    }
    Insert(root, num);
  }
  bool result = true;
  BFactor(root, result);
  std::cout << (result ? "YES" : "NO");
  Clear(root);
  return 0;
}