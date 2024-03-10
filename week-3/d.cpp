#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Graph {
private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Colors> colors_;

public:
  explicit Graph(int n) {
    vertices_.resize(n);
    colors_.resize(n, White);
    for (int i = 0; i < n; i++) {
      int desc = 0;
      std::cin >> desc;
      vertices_[i].push_back(--desc);
      vertices_[desc].push_back(i);
    }
  }

  void DFS(int index) {
    colors_[index] = Grey;
    for (auto &i : vertices_[index]) {
      if (colors_[i] == White) {
        DFS(i);
      }
    }
    colors_[index] = Black;
  }

  int ComponentCounter() {
    int count = 0;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White) {
        count++;
        DFS(i);
      }
    }
    return count;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  Graph graph(n);
  std::cout << graph.ComponentCounter();
  return 0;
}
