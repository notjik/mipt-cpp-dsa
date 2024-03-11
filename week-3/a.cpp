#include <iostream>
#include <vector>

enum Colors { White, Grey, Blue, Red };

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Colors> colors_;

 public:
  explicit Graph(int n, int m) {
    vertices_.resize(n);
    colors_.resize(n, White);
    for (int i = 0; i < m; i++) {
      int src = 0;
      int desc = 0;
      std::cin >> src >> desc;
      vertices_[--src].push_back(--desc);
      vertices_[desc].push_back(src);
    }
  }

  bool IsBipartite(int index, int count) {
    bool result = true;
    colors_[index] = Grey;
    count++;
    for (auto &i : vertices_[index]) {
      if (colors_[i] == White) {
        result = result && IsBipartite(i, count);
      } else if (colors_[i] == (!(count % 2) ? Blue : Red)) {
        return false;
      }
    }
    count--;
    colors_[index] = (count % 2 ? Blue : Red);
    return result;
  }

  bool IsBipartiteAll() {
    bool result = true;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White) {
        result = result && IsBipartite(i, 0);
      }
    }
    return result;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  Graph graph(n, m);
  std::cout << (graph.IsBipartiteAll() ? "YES" : "NO");
  return 0;
}
