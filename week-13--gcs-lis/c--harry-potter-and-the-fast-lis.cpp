#include <climits>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  auto arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  auto dp = new int[n + 1];
  dp[0] = INT_MIN;
  for (int i = 1; i < n + 1; ++i) {
    dp[i] = INT_MAX;
  }
  for (int i = 0; i < n; i++) {
    int left = -1;
    int right = n;
    while (left < right - 1) {
      int mid = (left + right) / 2;
      if (dp[mid] < arr[i]) {
        left = mid;
      } else {
        right = mid;
      }
    }
    if (dp[right - 1] < arr[i] && arr[i] < dp[right]) {
      dp[right] = arr[i];
    }
  }
  int counter = 0;
  for (int i = 1; i < n + 1; i++) {
    if (dp[i] != INT_MAX && dp[i] != INT_MIN) {
      counter++;
    }
  }
  std::cout << counter;
  delete[] dp;
  delete[] arr;
  return 0;
}
