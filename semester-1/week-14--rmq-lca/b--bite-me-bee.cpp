#include <cmath>
#include <iostream>

struct Node {
  int result = 0;
  int left;
  int right;
  int promise = 0;
};

void BuildTree(Node* tree, int* arr, int n) {
  for (int i = 0; i < n; i++) {
    tree[n - 1 + i] = {arr[i], i, i};
  }
  for (int i = n - 2; i >= 0; i--) {
    tree[i].result = std::max(tree[2 * i + 1].result, tree[2 * i + 2].result);
    tree[i].left = tree[2 * i + 1].left;
    tree[i].right = tree[2 * i + 2].right;
  }
}

void Push(Node* tree, int i) {
  tree[2 * i + 1].promise += tree[i].promise;
  tree[2 * i + 2].promise += tree[i].promise;
  tree[i].promise = 0;
}

void Update(Node* tree, int add, int l, int r, int i) {
  int left = tree[i].left;
  int right = tree[i].right;
  if ((right < l) || (left > r)) {
    return;
  }
  if ((left >= l) && (right <= r)) {
    tree[i].promise += add;
    return;
  }
  Push(tree, i);
  Update(tree, add, l, r, 2 * i + 1);
  Update(tree, add, l, r, 2 * i + 2);
  tree[i].result =
      std::max(tree[2 * i + 1].result + tree[2 * i + 1].promise, tree[2 * i + 2].result + tree[2 * i + 2].promise);
}

int Query(Node* tree, int l, int r, int i) {
  int left = tree[i].left;
  int right = tree[i].right;
  if ((right < l) || (left > r)) {
    return 0;
  }
  if ((left >= l) && (right <= r)) {
    return tree[i].result + tree[i].promise;
  }
  Push(tree, i);
  int ans = std::max(Query(tree, l, r, 2 * i + 1), Query(tree, l, r, 2 * i + 2));
  tree[i].result =
      std::max(tree[2 * i + 1].result + tree[2 * i + 1].promise, tree[2 * i + 2].result + tree[2 * i + 2].promise);
  return ans;
}

int Size(int i) {
  int x = 1;
  while (x < i) {
    x <<= 1;
  }
  return x;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n;
  int size = Size(n);
  Node* tree = new Node[2 * size - 1];
  int* arr = new int[2 * size - 1]();
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  BuildTree(tree, arr, size);
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    char command = 0;
    int l = 0;
    int r = 0;
    std::cin >> command >> l >> r;
    --l;
    --r;
    if (command == 'm') {
      std::cout << Query(tree, l, r, 0) << " ";
    } else {
      int add = 0;
      std::cin >> add;
      Update(tree, add, l, r, 0);
    }
  }
  delete[] tree;
  delete[] arr;
}
