/*
 * D. Сортировка подсчетом
=======================

Ограничение времени | 1 секунда
------------------- | ---------
Ограничение памяти  | 64Mb
Ввод                | стандартный ввод или input.txt
Вывод               | стандартный вывод или output.txt

Вам предлагается отсортировать данные метеостанции, которые к Вам поступили.

Известно, что Вам на вход подается набор целых чисел - округленную температуру.

Формат ввода
------------

В первой строке вводится число **N** - количество чисел, которые надо будет отсортировать.

На следующих **N** строчках следуют числа.

Формат вывода
-------------

Вывести **N** отсортированных чисел, каждое с новой строки.

Пример
------

Ввод | Вывод
---- | -----
10   | -18
29   | -15
-18  | -6
24   | -3
-15  | 6
14   | 9
37   | 14
9    | 24
6    | 29
-6   | 37
-3   |
*/
#include <iostream>

int Min(const int* arr, int size) {
  int min = 1000000;
  for (int i = 0; i < size; i++) {
    min = (min > arr[i] ? arr[i] : min);
  }
  return min;
}

int Max(const int* arr, int size) {
  int max = 0;
  for (int i = 0; i < size; i++) {
    max = (max < arr[i] ? arr[i] : max);
  }
  return max;
}

void CountingSort(int* arr, int size) {
  int max = Max(arr, size);
  int min = Min(arr, size);
  int* count = new int[max - min + 1];
  for (int i = 0; i < max - min + 1; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    count[arr[i] - min]++;
  }
  int index = 0;
  for (int i = 0; i < max - min + 1; i++) {
    while (count[i]-- > 0) {
      arr[index++] = i + min;
    }
  }
  delete[] count;
}

int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  CountingSort(arr, n);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << '\n';
  }
  delete[] arr;
  return 0;
}