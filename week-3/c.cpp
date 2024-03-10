#include <algorithm>
#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

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

  void DFS(int index, std::vector<int> &line) {
    colors_[index] = Grey;
    line.push_back(index);
    for (auto &i : vertices_[index]) {
      if (colors_[i] == White) {
        DFS(i, line);
      }
    }
    colors_[index] = Black;
  }

  void ComponentCounter() {
    int count = 0;
    std::vector<std::vector<int>> result;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White) {
        count++;
        std::vector<int> line;
        DFS(i, line);
        result.push_back(line);
      }
    }
    std::cout << count << '\n';
    for (auto &line : result) {
      std::cout << line.size() << '\n';
      for (auto &i : line) {
        std::cout << i + 1 << ' ';
      }
      std::cout << '\n';
    }
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
  graph.ComponentCounter();
  return 0;
}
