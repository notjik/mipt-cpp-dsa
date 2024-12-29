/*
 * I. Сортировка обменом (сортировка пузырьком)
Ограничение времени	1 секунда
Ограничение памяти	256.0 Мб
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Требуется отсортировать массив по неубыванию сортировкой пузырьком.

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

void BubbleSort(int *arr, const int size) {
  for (int i = 0; i < size; i++) {
    bool is_permutations = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        Swap(arr[j], arr[j + 1]);
        is_permutations = true;
      }
    }
    if (!is_permutations) {
      break;
    }
  }
}

int main() {
  int size;
  std::cin >> size;
  int *arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  BubbleSort(arr, size);
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}
