#include <iostream>
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

class CDU {
 public:
  int Kraskal();
  friend std::istream& operator>>(std::istream& is, CDU& cdu);

 private:
  std::vector<int> parent_;
  std::vector<Edge> edges_;
  std::vector<int> rank_;

  int FindSet(int idx);
  void Union(int first, int second);
};

std::istream& operator>>(std::istream& is, CDU& cdu) {
  int n = 0;
  int m = 0;
  is >> n >> m;
  cdu.parent_.resize(n, -1);
  cdu.rank_.resize(n, 1);
  for (int i = 0; i < m; i++) {
    int begin = 0;
    int end = 0;
    int weight = 0;
    is >> begin >> end >> weight;
    begin--;
    end--;
    Edge edge = Edge(begin, end, weight);
    cdu.edges_.push_back(edge);
  }
  return is;
}

int CDU::FindSet(int idx) {
  if (parent_[idx] == -1) {
    return idx;
  }
  return parent_[idx] = FindSet(parent_[idx]);
}

void CDU::Union(int first, int second) {
  int leader_first = FindSet(first);
  int leader_second = FindSet(second);
  if (rank_[leader_first] > rank_[leader_second]) {
    parent_[leader_second] = leader_first;
  } else if (rank_[leader_first] < rank_[leader_second]) {
    parent_[leader_first] = leader_second;
  } else {
    parent_[leader_second] = leader_first;
    rank_[leader_first]++;
  }
}

int CDU::Kraskal() {
  int weight = 0;
  for (auto& edge : edges_) {
    if (FindSet(edge.begin) != FindSet(edge.end)) {
      Union(edge.begin, edge.end);
      weight += edge.weight;
    }
  }
  return weight;
}

int main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::istream::sync_with_stdio(false);
  CDU cdu;
  std::cin >> cdu;
  std::cout << cdu.Kraskal();
  return 0;
}
