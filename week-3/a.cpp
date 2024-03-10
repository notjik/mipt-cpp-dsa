// Not end
#include <iostream>
#include <vector>

enum Colors { White, Red, Blue };

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

  bool IsBipartite(int index, int &count) {
    colors_[index] = (count % 2 ? Red : Blue);
    count++;
    for (auto &i : vertices_[index]) {
      if (colors_[i] == White || colors_[i] == (count % 2 ? Red : Blue)) {
        colors_[i] = (count % 2 ? Red : Blue);
      } else {
        return false;
      }
    }
    for (auto &i : vertices_[index]) {
      return IsBipartite(i, count);
    }
    return true;
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
  int count = 0;
  std::cout << (graph.IsBipartite(0, count) ? "YES" : "NO");
  return 0;
}
