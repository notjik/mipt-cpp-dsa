#include <climits>
#include <iostream>
#include <set>
#include <vector>

class Edge {
 public:
  int begin;
  int end;
  int weight;

  Edge(int src, int dest, int w) : begin(src), end(dest), weight(w) {
  }

  bool operator<(const Edge& other) const {
    return weight < other.weight;
  }
};

class Vertex {
 public:
  std::vector<Edge> neighbours;
};

class Graph {
 public:
  int Prim();
  friend std::istream& operator>>(std::istream& is, Graph& graph);

 private:
  std::vector<Vertex> vertecies_;
};

std::istream& operator>>(std::istream& is, Graph& graph) {
  int n = 0;
  int m = 0;
  is >> n >> m;
  graph.vertecies_.resize(n);
  for (int i = 0; i < m; i++) {
    int begin = 0;
    int end = 0;
    int weight = 0;
    is >> begin >> end >> weight;
    begin--;
    end--;
    Edge edge = Edge(begin, end, weight);
    Edge rev_edge = Edge(end, begin, weight);
    graph.vertecies_[begin].neighbours.emplace_back(edge);
    graph.vertecies_[end].neighbours.emplace_back(rev_edge);
  }
  return is;
}

int Graph::Prim() {
  std::vector<int> dist(vertecies_.size(), INT_MAX);
  std::vector<bool> used(vertecies_.size(), false);
  std::multiset<Edge> edges;
  int r = 0;
  dist[r] = 0;
  used[r] = true;
  int sum = 0;
  for (auto& i : vertecies_[r].neighbours) {
    edges.insert(i);
  }
  while (!edges.empty()) {
    Edge v = *edges.begin();
    edges.erase(edges.begin());
    if (used[v.end]) {
      continue;
    }
    used[v.end] = true;
    sum += v.weight;
    for (auto j : vertecies_[v.end].neighbours) {
      if (!used[j.end] && dist[j.end] > j.weight) {
        dist[j.end] = j.weight;
        edges.insert(j);
      }
    }
  }
  return sum;
}

int main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::istream::sync_with_stdio(false);
  Graph graph;
  std::cin >> graph;
  std::cout << graph.Prim();
  return 0;
}