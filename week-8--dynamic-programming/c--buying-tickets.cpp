#include <iostream>
#include <climits>

int Min(int a, int b) {
  return (a < b ? a : b);
}

int main() {
  int n;
  std::cin >> n;
  auto one = new int[n];
  auto two = new int[n];
  auto three = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> one[i] >> two[i] >> three[i];
  }
  auto res = new int[n];
  for (int i = 0; i < n; i++) {
    res[i] = Min(Min((i > 0 ? res[i - 1] : 0) + one[i], (i > 0 ? (i > 1 ? res[i - 2] : 0) + two[i - 1] : INT_MAX)),
                 (i > 1 ? (i > 2 ? res[i - 3] : 0) + three[i - 2] : INT_MAX));
  }
  std::cout << res[n - 1];
  delete[] one;
  delete[] two;
  delete[] three;
  delete[] res;
  return 0;
}
