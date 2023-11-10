#include <algorithm>
#include <iostream>

int main() {
  int w, n;
  std::cin >> w >> n;
  int** dp = new int*[n + 1];
  for (int i = 0; i < n + 1; i++) {
    dp[i] = new int[w + 1];
  }
  for (int i = 0; i < n + 1; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i < w + 1; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i < n + 1; i++) {
    int cur_c, cur_w;
    std::cin >> cur_c >> cur_w;
    for (int j = 1; j < w + 1; j++) {
      if (cur_w <= j) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - cur_w] + cur_c);

      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  {
    int i = w;
    while (i >= 0 && dp[n][i] == dp[n][i - 1]) {
      i--;
    }
    std::cout << dp[n][i] << ' ' << i;
  }
  for (int i = 0; i < n + 1; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}