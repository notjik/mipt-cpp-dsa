#include <iostream>

int main() {
  int n;
  std::cin >> n;
  auto arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  auto dp = new int[n];
  auto prev = new int[n];
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    prev[i] = -1;
    for (int j = 0; j < i; j++) {
      if ((arr[j] < arr[i]) && (dp[j] + 1 > dp[i])) {
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
    }
  }
  int len = 0;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] > len) {
      len = dp[i];
      index = i;
    }
  }
  auto res = new int[len];
  int count = len - 1;
  while (index != -1) {
    res[count] = arr[index];
    index = prev[index];
    count--;
  }
  for (int i = 0; i < len; i++) {
    std::cout << res[i] << " ";
  }
  delete[] arr;
  delete[] dp;
  delete[] prev;
  delete[] res;
}
