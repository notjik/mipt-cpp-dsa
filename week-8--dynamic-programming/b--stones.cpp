#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << (n % 3 != 0 ? '1' : '2');
}