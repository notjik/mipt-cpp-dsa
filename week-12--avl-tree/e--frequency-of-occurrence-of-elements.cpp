#include <iostream>

struct Node {
  int val;
  int count;
  int height;
  Node* left;
  Node* right;

  explicit Node(int key) : val(key), count(1), height(1), left(nullptr), right(nullptr){};
};

class AVL {
 private:
  Node* LeftRotate(Node* node);
  Node* RightRotate(Node* node);
  int BFactor(Node* node);
  void FixHeight(Node* node);
  int Height(Node* node);
  Node* Balance(Node* node);
  Node* FindMin(Node* node);
  Node* DelMin(Node* node);

 public:
  Node* Insert(Node* node, int key);
  Node* Remove(Node* node, int key);
  void Inorder(Node* node);
  void Delete(Node* node);
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
  if (node->val == key) {
    node->count++;
  }
  return Balance(node);
}

void AVL::Inorder(Node* node) {
  if (node != nullptr) {
    Inorder(node->left);
    std::cout << node->val << ' ' << node->count << '\n';
    Inorder(node->right);
  }
}

Node* AVL::FindMin(Node* node) {
  if (node->left == nullptr) {
    return node;
  }
  return FindMin(node->left);
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
    Node* min = FindMin(right);
    min->right = DelMin(right);
    min->left = left;
    return Balance(min);
  }
  return Balance(node);
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
  int key;
  std::cin >> key;
  while (key != 0) {
    root = avl.Insert(root, key);
    std::cin >> key;
  }
  avl.Inorder(root);
  avl.Delete(root);
  return 0;
}