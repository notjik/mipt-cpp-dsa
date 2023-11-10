#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int s;
  std::cin >> s;
  int* money = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> money[i];
  }
  int* dp = new int[s + 1];

  for (int i = 0; i <= s; i++) {
    dp[i] = 10e9;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    dp[money[i]] = 1;
  }
  for (int i = 1; i <= s; i++) {
    for (int j = 0; j < n; j++) {
      dp[i] = (money[j] <= i && dp[i] > dp[i - money[j]] + 1) ? dp[i - money[j]] + 1 : dp[i];
    }
  }
  if (dp[s] != 10e9) {
    std::cout << dp[s] << '\n';
    while (s > 0) {
      for (int i = 0; i < n; i++) {
        if (money[i] <= s && dp[s] == dp[s - money[i]] + 1) {
          std::cout << money[i] << ' ';
          s -= money[i];
        }
      }
    }
  } else {
    std::cout << "-1";
  }
  delete[] dp;
}