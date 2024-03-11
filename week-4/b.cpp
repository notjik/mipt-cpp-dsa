#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Vertex {
 public:
  Vertex() = default;
  explicit Vertex(int idx) : idx_(idx) {
  }
  Colors color_ = White;
  int idx_;
};

class Graph {
 private:
  std::vector<std::vector<int>> neighbours_;
  std::vector<Vertex> vertices_;
  std::vector<int> component_;
  std::vector<int> top_sorted_;

  void TopSortDFS(Vertex &vertex);
  Graph Reverse();
  void DFS(Vertex &vertex, int k);
  void ClearVertices();

 public:
  void TopSort();
  void FindComponent();

  friend std::istream &operator>>(std::istream &is, Graph &graph);
};

void Graph::DFS(Vertex &vertex, int k) {
  vertex.color_ = Grey;
  component_[vertex.idx_] = k;

  for (auto &i : neighbours_[vertex.idx_]) {
    if (vertices_[i].color_ == White) {
      DFS(vertices_[i], k);
    }
  }
  vertex.color_ = Black;
}

void Graph::TopSortDFS(Vertex &vertex) {
  vertex.color_ = Grey;
  for (auto &i : neighbours_[vertex.idx_]) {
    if (vertices_[i].color_ == White) {
      TopSortDFS(vertices_[i]);
    }
  }
  top_sorted_.push_back(vertex.idx_);
  vertex.color_ = Black;
}

void Graph::TopSort() {
  for (size_t i = 0; i < neighbours_.size(); i++) {
    if (vertices_[i].color_ == White) {
      TopSortDFS(vertices_[i]);
    }
  }
  ClearVertices();
}

void Graph::ClearVertices() {
  for (auto &i : vertices_) {
    i.color_ = White;
  }
}

Graph Graph::Reverse() {
  Graph copy;
  copy.neighbours_.resize(vertices_.size());
  copy.vertices_.resize(vertices_.size());
  copy.component_.resize(vertices_.size());

  for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {

    copy.vertices_[i].idx_ = i;

    for (int j = 0; j < static_cast<int>(neighbours_[i].size()); j++) {
      copy.neighbours_[neighbours_[i][j]].push_back(i);
    }
  }

  return copy;
}

void Graph::FindComponent() {
  TopSort();
  int k = 0;
  Graph reverse_graph = Reverse();

  for (int i = static_cast<int>(top_sorted_.size()) - 1; i >= 0; i--) {
    if (reverse_graph.vertices_[top_sorted_[i]].color_ == White) {
      reverse_graph.DFS(reverse_graph.vertices_[top_sorted_[i]], ++k);
    }
  }

  std::cout << k << '\n';

  for (auto i : reverse_graph.component_) {
    std::cout << i << " ";
  }
}

std::istream &operator>>(std::istream &is, Graph &graph) {
  int n = 0;
  int m = 0;
  is >> n >> m;
  graph.neighbours_.resize(n);
  graph.vertices_.resize(n);

  for (int i = 0; i < n; i++) {
    graph.vertices_[i].idx_ = i;
  }

  for (int i = 0; i < m; i++) {
    int from = 0;
    int to = 0;
    is >> from >> to;
    graph.neighbours_[--from].push_back(--to);
  }

  return is;
}

int main() {
  Graph graph;
  std::cin >> graph;
  graph.FindComponent();
  return 0;
}