/*
 * F. Сортировка слиянием
Ограничение времени	1.5 секунд
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Мало кто знает, что изначально знаменитый фильм ужасов Стэнли Кубрика должен был называться "Слияние". Название не пошло в прокат, т.к. режиссер не смог объяснить своим детям, почему сортировка слиянием вообще должна кого-то пугать. Попробуйте понять это сами, реализовывая её.

Формат ввода
В первой строке дано число N (1 ≤ N ≤ 105). Далее во второй строке идет N чисел через пробел, числа не превосходят по модулю 109.

Формат вывода
Вывести отсортированный по неубыванию массив.
 */
#include <iostream>

void Copy(int *first_begin, const int *first_end, int *second) {
  while (first_begin != first_end) {
    *(second++) = *(first_begin++);
  }
}

void Merge(int *first_begin, int *first_end, int *second_begin, int *second_end, int *result) {
  while (first_begin != first_end && second_begin != second_end) {
    if (*first_begin <= *second_begin) {
      *(result++) = *(first_begin++);
    } else {
      *(result++) = *(second_begin++);
    }
  }
  Copy(first_begin, first_end, result);
  Copy(second_begin, second_end, result);
}

void MergeSort(int *first_begin, int *first_end, int *result) {
  size_t size = first_end - first_begin;
  if (size <= 1) {
    return;
  }
  MergeSort(first_begin, first_begin + size / 2, result);
  MergeSort(first_begin + size / 2, first_end, result);
  Merge(first_begin, first_begin + size / 2, first_begin + size / 2, first_end, result);
  Copy(result, result + size, first_begin);
}

int main() {
  int n;
  std::cin >> n;
  int *first = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> first[i];
  }
  int *result = new int[n];
  MergeSort(first, first + n, result);
  for (int i = 0; i < n; i++) {
    std::cout << result[i] << ' ';
  }
  return 0;
}