#include <cmath>
#include <iostream>


int main() {
  int n = 0;
  int q = 0;
  int len;
  std::cin >> n;
  len = std::log2(n) + 1;
  int** st = new int*[len];
  for (int i = 0; i < len; i++) {
    st[i] = new int[n - (1 << i) + 1];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> st[0][i];
  }
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < (n - (1 << i) + 1); j++) {
      st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < (n - (1 << i) + 1); j++) {
      std::cout << st[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    l--;
    r--;
    int sub_len = std::log2(r - l);
    std::cout << std::min(st[sub_len][l],st[sub_len][r - (1 << sub_len) + 1]);
  }
  for (int i = 0; i < len; i++) {
    delete[] st[i];
  }
  delete[] st;
}
