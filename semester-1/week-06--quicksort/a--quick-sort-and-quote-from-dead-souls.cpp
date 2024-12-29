/*
 * **A. Быстрая сортировка и цитата из "Мертвых душ"**

**Ограничение времени:** 3 секунды

**Ограничение памяти:** 256 Мб

**Ввод:** стандартный ввод или input.txt

**Вывод:** стандартный вывод или output.txt

Какой же русский не любит быстрой сортировки? Реализуйте её.

**Формат ввода:**

В первой строке дано число N (1 ≤ N ≤ 105). Далее во второй строке идет N чисел через пробел, числа не превосходят по модулю 109.

**Формат вывода:**

Вывести отсортированный по неубыванию массив.

**Пример:**

**Ввод:**
```
5
5 2 3 1 4
```

**Вывод:**
```
1 2 3 4 5
```
 */
#include <iostream>

int Partition(int* arr, int left, int right) {
  int pivot = arr[left];
  int i = left + 1;
  int j = right;
  while (true) {
    while (i <= j && arr[i] <= pivot) {
      i++;
    }
    while (arr[j] >= pivot && j >= i) {
      j--;
    }
    if (j < i) {
      break;
    }
    std::swap(arr[i], arr[j]);
  }
  std::swap(arr[left], arr[j]);
  return j;
}

void QuickSortBackend(int* arr, int left, int right) {
  if (left < right) {
    int pivot_index = Partition(arr, left, right);
    QuickSortBackend(arr, left, pivot_index - 1);
    QuickSortBackend(arr, pivot_index + 1, right);
  }
}

void QuickSort(int* arr, int size) { QuickSortBackend(arr, 0, size - 1); }

int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSort(arr, n);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }
  delete[] arr;
  return 0;
}
