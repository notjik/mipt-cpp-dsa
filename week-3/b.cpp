#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Colors> colors_;
  std::vector<int> parents_;
  std::vector<int> cycle_;

 public:
  explicit Graph(int n, int m) {
    vertices_.resize(n);
    colors_.resize(n, White);
    parents_.resize(n, -1);
    for (int i = 0; i < m; i++) {
      int src = 0;
      int desc = 0;
      std::cin >> src >> desc;
      vertices_[--src].push_back(--desc);
    }
  }

  bool IsCycleExist(int index, int& start, int& end) {
    colors_[index] = Grey;
    for (auto& i : vertices_[index]) {
      if (colors_[i] == Grey) {
        start = i;
        end = index;
        return true;
      }
      if (colors_[i] == White) {
        parents_[i] = index;
        if (IsCycleExist(i, start, end)) {
          return true;
        }
      }
    }
    colors_[index] = Black;
    return false;
  }

  void FindCycle() {
    int start = -1;
    int end = 0;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White && IsCycleExist(i, start, end)) {
        break;
      }
    }
    if (start == -1) {
      std::cout << "NO";
    } else {
      for (int vertex = end; vertex != start; vertex = parents_[vertex]) {
        cycle_.push_back(vertex);
      }
      cycle_.push_back(start);
      std::cout << "YES" << '\n';
      for (int i = static_cast<int>(cycle_.size()) - 1; i >= 0; i--) {
        std::cout << cycle_[i] + 1 << " ";
      }
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
  graph.FindCycle();
  return 0;
}
