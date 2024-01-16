/*
 * J. Пузырьковая сортировка: количество обменов
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Определите, сколько обменов сделает алгоритм пузырьковой сортировки по возрастанию для данного массива.
Формат ввода
На первой строке дано число n (1≤n≤1000) – количество элементов в массиве.
На второй строке — сам массив. Гарантируется, что все элементы массива различны и не превышают по модулю 10^9.

Формат вывода
Выведите одно число — количество обменов пузырьковой сортировки.
 */
#include <iostream>

void Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int CountPermutationsInBubbleSort(int *arr, const int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    bool is_permutations = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        Swap(arr[j], arr[j + 1]);
        count++;
        is_permutations = true;
      }
    }
    if (!is_permutations) {
      break;
    }
  }
  return count;
}

int main() {
  int size;
  std::cin >> size;
  int *arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  std::cout << CountPermutationsInBubbleSort(arr, size);
  delete[] arr;
  return 0;
}
