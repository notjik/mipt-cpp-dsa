#include <iostream>

int main() {
  char str[100001];
  std::cin >> str;
  int del = 0;
  int open = 0;
  {
    int cur = 0;
    while (str[cur] != '\0') {
      if (str[cur] == '(') {
        open++;
      } else if (str[cur] == ')') {
        if (open > 0) {
          open--;
        } else {
          del++;
        }
      }
      cur++;
    }
  }
  std::cout << del + open;
  return 0;
}
