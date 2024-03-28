#include <iostream>
#include <list>
#include <vector>

enum Colors { White, Grey, Black };

class NoCycle : public std::exception {
  const char* what() const noexcept override {
    return "No cycle!";
  }
};

class CycleExist : public std::exception {
  const char* what() const noexcept override {
    return "Cycle!";
  }
};

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<Colors> colors_;
  std::vector<int> parents_;
  using Cycle = std::vector<int>;

 public:
  friend std::istream& operator>>(std::istream& is, Graph& graph) {
    int n = 0;
    int m = 0;
    is >> n >> m;
    graph.vertices_.resize(n);
    graph.colors_.resize(n, White);
    graph.parents_.resize(n - 1, -1);
    for (int i = 0; i < m; i++) {
      int from = 0;
      int to = 0;
      is >> from >> to;
      graph.vertices_[--from].push_back(--to);
    }

    return is;
  }

  void DFS(int index) {
    colors_[index] = Grey;
    // std::cout << index << " ";
    for (auto& i : vertices_[index]) {
      if (colors_[i] == White) {
        DFS(i);
      }
    }
    colors_[index] = Black;
  }

  bool IsCycleExist(int index, Cycle& result) {
    colors_[index] = Grey;
    // std::cout << index << " ";
    for (auto& i : vertices_[index]) {
      if (colors_[i] == Grey) {
        result.push_back(i);
        result.push_back(index);
        return true;
      }
      if (colors_[i] == White) {
        parents_[i] = index;
        if (IsCycleExist(i, result)) {
          return true;
        }
      }
    }
    colors_[index] = Black;
    return false;
  }

  bool TopSortDFS(int index, std::vector<int>& answer) {
    colors_[index] = Grey;
    // std::cout << index << " ";
    for (auto& i : vertices_[index]) {
      if (colors_[i] == Grey) {
        return true;
      }
      if (colors_[i] == White) {
        if (TopSortDFS(i, answer)) {
          return true;
        }
      }
    }
    answer.push_back(index);
    colors_[index] = Black;
    return false;
  }

  std::vector<int> TopSort() {
    std::vector<int> answer;
    for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
      if (colors_[i] == White) {
        if (TopSortDFS(i, answer)) {
          throw CycleExist();
        }
      }
    }
    return {answer.rbegin(), answer.rend()};
  }
};

int main() {
  Graph graph;
  std::cin >> graph;
  try {
    std::vector<int> top_sorted = graph.TopSort();
    for (auto i : top_sorted) {
      std::cout << i + 1 << " ";
    }
  } catch (CycleExist err) {
    std::cout << -1;
  }
  return 0;
}
