#include <iostream>
#include <list>
#include <vector>

enum Colors { White, Grey, Black };

class NoCycle : public std::exception {
  const char* what() const noexcept override { return "No cycle!"; }
};

class CycleExist : public std::exception {
  const char* what() const noexcept override { return "Cycle!"; }
};

class Graph {
 private:
  std::vector<std::vector<int>> vertices;
  std::vector<Colors> colors;
  std::vector<int> parents;
  using Cycle = std::vector<int>;

 public:
  Graph(std::vector<std::vector<int>> other_vertices)
      : vertices(std::move(other_vertices)),
        colors(std::vector<Colors>(vertices.size(), White)),
        parents(std::vector<int>(vertices.size() - 1, -1)) {}

  void DFS(int index) {
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
        if (IsCycleExist(i, result)) {
          return true;
        }
      }
    }
    colors[index] = Black;
    return false;
  }

  bool TopSortDFS(int index, std::vector<int>& answer) {
    colors[index] = Grey;
    // std::cout << index << " ";
    for (auto& i : vertices[index]) {
      if (colors[i] == Grey) {
        return true;
      }
      if (colors[i] == White) {
        if (TopSortDFS(i, answer)) {
          return true;
        }
      }
    }
    answer.push_back(index);
    colors[index] = Black;
    return false;
  }

  std::vector<int> TopSort() {
    std::vector<int> answer;
    for (int i = 0; i < static_cast<int>(vertices.size()); i++) {
      if (colors[i] == White) {
        if (TopSortDFS(i, answer)) {
          throw CycleExist();
        }
      }
    }
    return {answer.rbegin(), answer.rend()};
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
    for (int start = parents[result.back()]; parents.back() != result.front();
         start = parents[start]) {
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
  int ComponentCounter() {
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
  Graph graph({{1, 3}, {}, {1}, {2}});
  std::vector<int> top_sorted = graph.TopSort();
  for (auto i : top_sorted) {
    std::cout << i << " ";
  }
  return 0;
}

// для курсоров
