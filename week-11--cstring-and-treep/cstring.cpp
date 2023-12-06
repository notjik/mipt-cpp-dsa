#include "cstring.h"

size_t Strlen(const char* str) {
  size_t i = 0;
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

char* Strcpy(char* dest, const char* src) {
  size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char* Strncpy(char* dest, const char* src, size_t count) {
  size_t i = 0;
  while (src[i] != '\0' && i < count) {
    dest[i] = src[i];
    i++;
  }
  while (i < count) {
    dest[i] = '\0';
    i++;
  }
  return dest;
}

char* Strcat(char* dest, const char* src) {
  size_t size = Strlen(dest);
  size_t i = 0;
  while (src[i] != '\0') {
    dest[size + i] = src[i];
    i++;
  }
  dest[size + i] = '\0';
  return dest;
}

char* Strncat(char* dest, const char* src, size_t count) {
  size_t size = Strlen(dest);
  size_t i = 0;
  while (src[i] != '\0' && i < count) {
    dest[size + i] = src[i];
    i++;
  }
  while (i < count) {
    dest[size + i] = '\0';
    i++;
  }
  return dest;
}

const char* Strchr(const char* str, char symbol) {
  size_t size = Strlen(str);
  size_t i = 0;
  while (i <= size) {
    if (*(str + i) == symbol) {
      return str + i;
    }
    i++;
  }
  return nullptr;
}

const char* Strrchr(const char* str, char symbol) {
  size_t size = Strlen(str);
  size_t i = 0;
  while (i <= size) {
    if (*(str + size - i) == symbol) {
      return str + size - i;
    }
    i++;
  }
  return nullptr;
}

size_t Strspn(const char* dest, const char* src) {
  size_t result = 0;
  size_t i = 0;
  while (dest[i] != '\0') {
    size_t j = 0;
    while (src[j] != '\0') {
      if (src[j] == dest[i]) {
        i++;
        result++;
        break;
      }
      j++;
    }
    if (src[j] == '\0') {
      break;
    }
  }
  return result;
}

size_t Strcspn(const char* dest, const char* src) {
  size_t result = 0;
  size_t i = 0;
  while (dest[i] != '\0') {
    size_t j = 0;
    while (src[j] != '\0') {
      if (src[j] == dest[i]) {
        return result;
      }
      j++;
    }
    if (src[j] == '\0') {
      i++;
      result++;
    }
  }
  return result;
}

const char* Strpbrk(const char* dest, const char* breakset) {
  size_t i = 0;
  while (*(dest + i) != '\0') {
    size_t j = 0;
    while (*(breakset + j) != '\0') {
      if (*(breakset + j) == *(dest + i)) {
        return dest + i;
      }
      j++;
    }
    i++;
  }
  return nullptr;
}

const char* Strstr(const char* str, const char* pattern) {
  size_t i = 0;
  size_t length_pattern = Strlen(pattern);
  while (*(str + i) != '\0') {
    size_t j = 0;
    while (*(pattern + j) != '\0') {
      if (*(pattern + j) != *(str + i + j)) {
        break;
      }
      j++;
    }
    if (j == length_pattern) {
      return str + i;
    }
    i++;
  }
  return nullptr;
}