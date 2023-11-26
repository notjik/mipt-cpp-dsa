#include <iostream>

int main() {
  auto* regexp1 = new char[81];
  auto* regexp2 = new char[81];
  auto* res = new char[81]{};
  std::cin >> regexp1;
  std::cin >> regexp2;
  int cur1 = 0;
  int cur2 = 0;
  int i = 0;
  bool done = true;
  while (regexp1[cur1] != '\0' && regexp2[cur2] != '\0') {
    std::cout << regexp1[cur1] << ' ' << regexp2[cur2] << ' ' << res << '\n';
    if (regexp1[cur1] == '*' || regexp2[cur2] == '*') {
      if (regexp1[cur1] == regexp2[cur2]) {
        cur1++;
        cur2++;
      } else if (regexp1[cur1] == '*') {
        if (regexp1[cur1 + 1] == regexp2[cur2] || regexp1[cur1 + 1] == '?') {
          cur1++;
          if (regexp1[cur1] == '?' || regexp2[cur2] == '?') {
            if (regexp1[cur1] == regexp2[cur2]) {
              res[i++] = 'X';
              cur1++;
              cur2++;
            } else if (regexp1[cur1] == '?') {
              res[i++] = regexp2[cur2];
              cur1++;
              cur2++;
            } else {
              res[i++] = regexp1[cur1];
              cur1++;
              cur2++;
            }
          } else if (regexp1[cur1] == regexp2[cur2]) {
            res[i++] = regexp1[cur1];
            cur1++;
            cur2++;
          } else {
            done = false;
            break;
          }
        } else {
          res[i++] = regexp2[cur2++];
        }
      } else if (regexp2[cur2] == '*') {
        if (regexp1[cur1] == regexp2[cur2 + 1] || regexp2[cur2 + 1] == '?') {
          cur2++;
          if (regexp1[cur1] == '?' || regexp2[cur2] == '?') {
            if (regexp1[cur1] == regexp2[cur2]) {
              res[i++] = 'X';
              cur1++;
              cur2++;
            } else if (regexp1[cur1] == '?') {
              res[i++] = regexp2[cur2];
              cur1++;
              cur2++;
            } else {
              res[i++] = regexp1[cur1];
              cur1++;
              cur2++;
            }
          } else if (regexp1[cur1] == regexp2[cur2]) {
            res[i++] = regexp1[cur1];
            cur1++;
            cur2++;
          } else {
            done = false;
            break;
          }
        } else {
          res[i++] = regexp1[cur1++];
        }
      }
    } else {
      if (regexp1[cur1] == '?' || regexp2[cur2] == '?') {
        if (regexp1[cur1] == regexp2[cur2]) {
          res[i++] = 'X';
          cur1++;
          cur2++;
        } else if (regexp1[cur1] == '?') {
          res[i++] = regexp2[cur2];
          cur1++;
          cur2++;
        } else {
          res[i++] = regexp1[cur1];
          cur1++;
          cur2++;
        }
      } else if (regexp1[cur1] == regexp2[cur2]) {
        res[i++] = regexp1[cur1];
        cur1++;
        cur2++;
      } else {
        done = false;
        break;
      }
    }
  }
  while (regexp1[cur1] == '*') {
    cur1++;
  }
  while (regexp2[cur2] == '*') {
    cur2++;
  }
  res[i] = '\0';
  if (done && regexp1[cur1] == '\0' && regexp2[cur2] == '\0') {
    std::cout << res;
  } else {
    std::cout << "No solution";
  }
  delete[] regexp1;
  delete[] regexp2;
  delete[] res;
  return 0;
}