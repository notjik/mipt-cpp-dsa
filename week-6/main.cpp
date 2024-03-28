#include <iostream>
#include <queue>
#include <vector>
#include <climits>



class Graph {
 private:
  std::vector<std::vector<int>> matrix_;
 public:
  void Floyd();
  friend std::istream& operator>>(std::istream& is, Graph& graph);
};

std::istream& operator>>(std::istream& is, Graph& graph) {
  int n = 0;
  is >> n;
  graph.matrix_.resize(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
      is >> graph.matrix_[i][j];
    }
  }
  return is;
}


void Graph::Floyd() {
  int size = static_cast<int>(matrix_.size());
  for (int k = 0; k < size; k++) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        matrix_[i][j] = std::min(matrix_[i][j], matrix_[i][k] + matrix_[k][j]);
      }
    }
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cout << matrix_[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  Graph graph;
  std::cin >> graph;
  graph.Floyd();
  return 0;
}


// cursor ->