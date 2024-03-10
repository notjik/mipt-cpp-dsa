#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <climits>


class Graph {
private:
  std::vector<std::vector<int>> matrix_;
  std::vector<int> parent_;
  std::vector<bool> used_;
  std::vector<int> distance_;
public:
  Graph(int n) {
    matrix_.resize(n);
    for (auto &row : matrix_) {
      row.resize(n);
      for (int i = 0; i < n; i++) {
        int distance = 0;
        std::cin >> distance;
        row[i] = distance;
      }
    }
    parent_.resize(n, -1);
    used_.resize(n, false);
    distance_.resize(n, 1e6);
  }

  void Dijkstra(int start, int end){
    distance_[start] = 0;
    for (int i = 0; i < static_cast<int>(distance_.size()); i++) {
      int v = -1;
      for (int j = 0; j < static_cast<int>(distance_.size()); j++) {
        if (!used_[j] && (v == -1 || (distance_[j] < distance_[i]))) {
          v = j;
        }
      }
      if (distance_[v] == 1e6) {
        break;
      }
      used_[v] = true;
      for(int to = 0; to < static_cast<int>(distance_.size()); to++) {
        if(matrix_[v][to] != -1) {
          distance_[to] = std::min(distance_[to], distance_[v] + matrix_[v][to]);
        }
      }
    }
    if(distance_[end] == 1e6) {
      std::cout << -1 << '\n';
    } else {
      std::cout << distance_[end] << '\n';
    }
  }
};



int main() {
  int n = 0;
  std::cin >> n;
  int s = 0;
  int f = 0;
  std::cin >> s >> f;
  Graph graph(n);
  graph.Dijkstra(--s, --f);
  return 0;
}