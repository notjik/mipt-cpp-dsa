#include <cstdint>
#include <iostream>
#include <random>

struct Node {
  int64_t val;
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
  Pair Split(Node* root, int64_t key);
  Node* FindBackend(Node* root, int64_t key);

 public:
  Node* Insert(Node* root, int64_t key, std::mt19937& gen);
  void Print(Node* root);
  void Delete(Node* root);
  Node* Remove(Node* root, int key);
  bool Find(Node* root, int64_t key);
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

Pair Treap::Split(Node* root, int64_t key) {
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

Node* Treap::FindBackend(Node* root, int64_t key) {
  if (root == nullptr || key == root->val) {
    return root;
  }
  if (key > root->val) {
    return FindBackend(root->right, key);
  }
  return FindBackend(root->left, key);
}

bool Treap::Find(Node* root, int64_t key) {
  Node* node = FindBackend(root, key);
  if (node == nullptr) {
    return false;
  }
  return node->val == key;
}

Node* Treap::Insert(Node* root, int64_t key, std::mt19937& gen) {
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
    std::cout << root->val << '\n';
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
  int64_t num;
  std::mt19937 gen;
  std::cin >> num;
  if (num != 0) {
    root = treap.Insert(root, num, gen);
  }
  while (num != 0) {
    std::cin >> num;
    if (num == 0) {
      break;
    }
    root = treap.Insert(root, num, gen);
  }
  treap.Print(root);
  treap.Delete(root);
  return 0;
}