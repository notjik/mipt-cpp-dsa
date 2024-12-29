/*
 *H. Сортировка вставками
Ограничение времени	1 секунда
Ограничение памяти	256.0 Мб
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Требуется отсортировать массив по неубыванию сортировкой вставками.

Формат ввода
В первой строке вводится одно натуральное число (0<n≤100) ~--- размер массива.

Во второй строке задаются
n
n чисел ~--- элементы массива (целые числа, не превосходящие по модулю 1000).

Формат вывода
Вывести получившийся массив.
 */
#include <iostream>

void InsertionSort(int *arr, const int size) {
  for (int i = 1; i < size; i++) {
    int x = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > x) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = x;
  }
}

int main() {
  int size;
  std::cin >> size;
  int *arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  InsertionSort(arr, size);
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}
