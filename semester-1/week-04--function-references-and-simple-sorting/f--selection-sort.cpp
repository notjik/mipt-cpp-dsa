/*
 * F. Сортировка выбором
Ограничение времени	1 секунда
Ограничение памяти	256.0 Мб
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Требуется отсортировать массив по неубыванию сортировкой выбором.

Формат ввода
В первой строке вводится одно натуральное число n (0<n≤100) ~--- размер массива.

Во второй строке задаются n чисел -- элементы массива (целые числа, не превосходящие по модулю 1000).

Формат вывода
Вывести получившийся массив.
 */
#include <iostream>

void Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void SelectionSort(int *arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    Swap(arr[i], arr[min_index]);
  }
}

int main() {
  int size;
  std::cin >> size;
  int *arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  SelectionSort(arr, size);
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}
