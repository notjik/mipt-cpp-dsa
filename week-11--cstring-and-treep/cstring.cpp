#include "cstring.h"

size_t Strlen(const char* str) {
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  return count;
}

int Strcmp(const char* first, const char* second) {
  while ((*first) && (*second) && (*first == *second)) {
    first++;
    second++;
  }
  return *first - *second;
}

int Strncmp(const char* first, const char* second, size_t count) {
  while ((*first) && (*second) && (*first == *second) && (count > 1)) {
    first++;
    second++;
    count--;
  }
  return (!count ? 0 : *first - *second);
}

int main() {
  char str1[] = {"cbc"};
  char str2[] = {"abc"};
  std::cout << Strncmp(str1, str2, 0);
}