#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int* fib = new int[n + 2];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < n + 2; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  std::cout << fib[n];
  delete[] fib;
}