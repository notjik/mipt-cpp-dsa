#include <cstring>
#include <iostream>
#include <random>

struct Node {
  int key;
  int priority;
  Node* left;
  Node* right;

  Node(int _key, std::mt19937& gen) : key(_key), left(nullptr), right(nullptr) {
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
 public:
  void Insert(Node* root, int key);
  void Print(Node* root);
  void Delete(Node* root);
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

Pair Treap::Split(Node* root, int x) {
  if (root == nullptr) {
    return {nullptr, nullptr};
  }
  if (x > root->key) {
    Pair pair = Split(root->right, x);
    root->right = pair.left;
    return {root, pair.right};
  }
  Pair pair = Split(root->left, x);
  root->left = pair.right;
  return {pair.left, root};
}

void Treap::Print(Node* root) {
  if (root != nullptr) {
    Print(root->left);
    std::cout << root->key << " " << root->priority << '\n';
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

int main() {
  std::mt19937 gen;
  Treap treap;
  Node* root = nullptr;
  treap.Insert(root, 2 * 2, gen);
  treap.Insert(root, 2 * 3, gen);
  treap.Insert(root, 2 * 6, gen);
  treap.Insert(root, 2 * 9, gen);
  treap.Insert(root, 2 * 7, gen);
  treap.Insert(root, 2 * 77, gen);
  treap.Insert(root, 2 * 0, gen);
  treap.Insert(root, 2 * 1, gen);
  treap.Print(root);
  return 0;
}