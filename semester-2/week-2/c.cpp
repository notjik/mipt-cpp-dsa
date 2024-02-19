#include <iostream>
#include <vector>

class Graph {
 private:
  size_t size_;
  std::vector<std::vector<int>> table_;

 public:
  explicit Graph(size_t size) {
    size_ = size;
    table_.resize(size);
    for (auto& i : table_) {
      i.resize(size);
    }
  }
  ~Graph() = default;

  void Insert(size_t i, size_t j) {
    table_[i][j] = 1;
    table_[j][i] = 1;
  }

  std::vector<int> GetChildren(size_t vertex) {
    std::vector<int> childrens;
    for (size_t i = 0; i < size_; i++) {
      if (table_[vertex][i] == 1) {
        childrens.push_back(i);
      }
    }
    return childrens;
  }

  size_t Degree(size_t vertex) {
    return GetChildren(vertex).size();
  }

  bool Connected(size_t from, size_t to) {
    return table_[from][to];
  }

  size_t RoadNumber() {
    size_t sum = 0;
    for (size_t i = 0; i < size_; i++) {
      for (size_t j = i + 1; j < size_; j++) {
        if (table_[i][j] == 1) {
          sum++;
        }
      }
    }
    return sum;
  }

  void Print() {
    for (auto i : table_) {
      for (int j : i) {
        std::cout << j << ' ';
      }
      std::cout << '\n';
    }
  }
};

int main() {
  size_t n;
  std::cin >> n;
  Graph graph(n);
  std::vector<int> color(n);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      int elem;
      std::cin >> elem;
      if (elem) {
        graph.Insert(i, j);
      }
    }
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> color[i];
  }
  size_t counter = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (graph.Connected(i, j) && (color[i] != color[j])) {
        counter++;
      }
    }
  }
  std::cout << counter;
  return 0;
}