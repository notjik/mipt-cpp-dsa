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
  size_t n, m;
  std::cin >> n >> m;
  Graph graph(n);
  for (size_t i = 0; i < m; i++) {
    int k = 0, l = 0;
    std::cin >> k >> l;
    graph.Insert(k - 1, l - 1);
  }
  for (size_t i = 0; i < n; i++) {
    std::cout << graph.Degree(i) << " ";
  }
  return 0;
}