#include "cstring.h"

size_t Strlen(const char* str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
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

char* Strcat(char* dest, const char* src) {
  int count_dest = Strlen(dest);
  int i = 0;
  while (src[i] != '\0') {
    dest[count_dest + i] = src[i];
    i++;
  }
  dest[count_dest + i] = '\0';
  return dest;
}

char* Strncat(char* dest, const char* src, size_t count) {
  int count_dest = Strlen(dest);
  int i = 0;
  while (src[i] != '\0' && i < count) {
    dest[count_dest + i] = src[i];
    i++;
  }
  while (i < count){
    dest[count_dest + i] = '\0';
    i++;
  }
  return dest;
}

int main() {
  char str1[] = {"cbc"};
  char str2[] = {"abc"};
  std::cout << Strncat(str1, str2, 2);
}