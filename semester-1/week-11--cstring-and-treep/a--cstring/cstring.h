#ifndef SUSU_MIPT_CPP_WEEK_11_CSTRING_AND_TREEP_A_CSTRING_CSTRING_H_
#define SUSU_MIPT_CPP_WEEK_11_CSTRING_AND_TREEP_A_CSTRING_CSTRING_H_

#include <iostream>

size_t Strlen(const char* str);

int Strcmp(const char* first, const char* second);

int Strncmp(const char* first, const char* second, size_t count);

char* Strcpy(char* dest, const char* src);

char* Strncpy(char* dest, const char* src, size_t count);

char* Strcat(char* dest, const char* src);

char* Strncat(char* dest, const char* src, size_t count);

const char* Strchr(const char* str, char symbol);

const char* Strrchr(const char* str, char symbol);

size_t Strspn(const char* dest, const char* src);

size_t Strcspn(const char* dest, const char* src);

const char* Strpbrk(const char* dest, const char* breakset);

const char* Strstr(const char* str, const char* pattern);

#endif  // SUSU_MIPT_CPP_WEEK_11_CSTRING_AND_TREEP_A_CSTRING_CSTRING_H_
