#include <iostream>

int main() {
  int n;
  std::cin >> n;
  auto first = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> first[i];
  }
  int m;
  std::cin >> m;
  auto second = new int[m];
  for (int i = 0; i < m; i++) {
    std::cin >> second[i];
  }
  auto dp = new int*[n + 1];
  for (int i = 0; i < n + 1; i++) {
    dp[i] = new int[m + 1]{};
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (first[i - 1] == second[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  auto res = new int[dp[n][m]];
  {
    int i = n;
    int j = m;
    while (dp[i][j]) {
      if (dp[i][j] == dp[i - 1][j]) {
        i--;
      } else if (dp[i][j] == dp[i][j - 1]) {
        j--;
      } else {
        res[dp[i][j] - 1] = first[i - 1];
        i--;
        j--;
      }
    }
  }
  for (int i = 0; i < dp[n][m]; i++) {
    std::cout << res[i] << " ";
  }
  delete[] first;
  delete[] second;
  for (int i = 0; i < n + 1; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  delete[] res;
  return 0;
}
