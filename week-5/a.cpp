#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {
 private:
  std::vector<std::vector<int>> vertices_;
  std::vector<int> distance_;
  std::vector<int> parents_;

 public:
  Graph(int n, int m) {
    distance_.resize(n, -1);
    vertices_.resize(n);
    parents_.resize(n, -1);
    for (int i = 0; i < m; i++) {
      int first = 0;
      int second = 0;
      std::cin >> first >> second;
      vertices_[--first].push_back(--second);
      vertices_[second].push_back(first);
    }
  }
  int BFS(int vertex, int destination);
  void FindShortestWay(int start, int end);
};

int Graph::BFS(int vertex, int destination) {
  std::queue<int> queue;
  distance_[vertex] = 0;
  parents_[vertex] = vertex;
  queue.push(vertex);
  while (!queue.empty()) {
    int parent = queue.front();
    queue.pop();
    for (int i : vertices_[parent]) {
      if (distance_[i] == -1) {
        queue.push(i);
        parents_[i] = parent;
        distance_[i] = distance_[parent] + 1;
      }
    }
  }
  return distance_[destination];
}

void Graph::FindShortestWay(int start, int end) {
  int distance = BFS(start, end);
  if (parents_[end] != -1) {
    std::vector<int> path;
    int current = end;
    while (parents_[current] != current) {
      path.push_back(current);
      current = parents_[current];
    }
    std::cout << distance << '\n';
    std::cout << start + 1 << ' ';
    for (int i = static_cast<int>(path.size() - 1); i >= 0; i--) {
      std::cout << path.at(i) + 1 << ' ';
    }
  } else {
    std::cout << -1;
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int a = 0;
  int b = 0;
  std::cin >> a >> b;
  Graph graph(n, m);
  graph.FindShortestWay(--a, --b);
  return 0;
}
