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
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      int input;
      std::cin >> input;
      graph.Insert(i, j, input);
    }
  }
  std::cout << graph.RoadNumber();
  return 0;
}