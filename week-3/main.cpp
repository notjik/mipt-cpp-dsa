#include <iostream>
#include <vector>
#include <list>


enum Colors {
  White,
  Grey,
  Black
};

class NoCycle : public std::exception {
  const char* what() const noexcept override {
    return "No cycle!";
  }
};

class Graph {
 private:
  std::vector<std::vector<int>> vertices;
  std::vector<Colors> colors;
  std::vector<int> parents;
  using Cycle = std::vector<int>;

 public:
  Graph(std::vector<std::vector<int>> other_vertices) :
      vertices(std::move(other_vertices)),
      colors(std::vector<Colors>(vertices.size(), White)),
      parents(std::vector<int>(vertices.size() - 1, -1)) {}

  void IsBipartite(int index) {
    colors[index] = Grey;
    // std::cout << index << " ";
    for (auto& i : vertices[index]) {
      if (colors[i] == White) {
        DFS(i);
      }
    }
    colors[index] = Black;
  }

  bool IsCycleExist(int index, Cycle& result) {
    colors[index] = Grey;
    // std::cout << index << " ";
    for (auto& i : vertices[index]) {
      if (colors[i] == Grey) {
        result.push_back(i);
        result.push_back(index);
        return true;
      }
      if (colors[i] == White) {
        parents[i] = index;
        if(IsCycleExist(i, result)){
          return true;
        }
      }
    }
    colors[index] = Black;
    return false;
  }

  Cycle FindCycle() {
    Cycle result;
    for (int i = 0; i < vertices.size(); i++) {
      if (colors[i] == White) {
        if (IsCycleExist(i, result)) {
          break;
        }
      }
    }
    if (result.empty()) {
      throw NoCycle();
    }
    for (int start = parents[result.back()]; parents.back() != result.front(); start = parents[start]) {
      result.push_back(start);
    }

    return {result.rbegin(), result.rend() - 1};
  }

  void DFSAll() {
    for (int i = 0; i < vertices.size(); i++) {
      if (colors[i] == White) {
        DFS(i);
      }
    }
  }
  int ComponentCounter () {
    int count = 0;
    for (int i = 0; i < vertices.size(); i++) {
      if (colors[i] == White) {
        count++;
        DFS(i);
      }
    }
    return count;
  }
};


int main() {
  Graph graph({{}, {}, {}, {}, {}});
  std::cout << graph.ComponentCounter();
  return 0;
}
