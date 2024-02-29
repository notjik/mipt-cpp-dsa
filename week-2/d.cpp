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

  void Insert(size_t i, size_t j, int elem) {
    table_[i][j] = elem;
    table_[j][i] = elem;
  }

  int Sum(size_t i, size_t j, size_t k) {
    return table_[i][j] + table_[i][k] + table_[j][k];
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
      graph.Insert(i, j, elem);
    }
  }
  auto ans = static_cast<int>(10e9);
  size_t ans_i = 0, ans_j = 0, ans_k = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      for (size_t k = j + 1; k < n; k++) {
        if (graph.Connected(i, j) && graph.Connected(j, k) && graph.Connected(k, i) && ans > graph.Sum(i, j, k)) {
          ans = graph.Sum(i, j, k);
          ans_i = i;
          ans_j = j;
          ans_k = k;
        }
      }
    }
  }
  std::cout << ans_i + 1 << ' ' << ans_j + 1 << ' ' << ans_k + 1;
  return 0;
}