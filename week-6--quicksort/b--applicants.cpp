/*
 * **B. Абитуриенты**

**Ограничение времени:** 1 секунда

**Ограничение памяти:** 256.0 Мб

**Ввод:** стандартный ввод или input.txt

**Вывод:** стандартный вывод или output.txt

Все вводные вымышлены, любые совпадения с реальностью случайны.

---

В ВУЗ поступает N человек. Приемная комиссия хочет набрать M групп по K человек. Главным критерием набора студентов в группы является комфортность обучения в каждой из них. Считается, что чем выше размах (разность между наибольшим и наименьшим значениями) баллов ЕГЭ внутри группы, тем она менее комфортна для обучения.

Необходимо составить группы так, чтобы максимальное значение размаха в баллах среди них было минимально (чтобы наиболее некомфортная группа была как можно более комфортной).

**Формат ввода:**

Вводятся числа N, M и K (1 ≤ M * K ≤ N ≤ 10^5). Далее идут N целых чисел --- балл ЕГЭ каждого из абитуриентов. С учетом индивидуальных достижений балл абитуриента не превосходит 10^9.

**Формат вывода:**

Выведите одно число --- наименьшее возможное значение максимального размаха.

**Пример:**

**Ввод:**
```
8 2 3
170
205
225
190
260
130
225
160
```

**Вывод:**
```
30
```
*/
#include <iostream>

int Partition(int* arr, int left, int right, bool& reverse) {
  int mid = (left + right) / 2;
  int pivot = arr[mid];
  while (left < right) {
    while (reverse ? arr[left] > pivot : arr[left] < pivot) {
      left++;
    }
    while (reverse ? arr[right] < pivot : arr[right] > pivot) {
      right--;
    }
    if (left >= right) {
      break;
    }
    std::swap(arr[left], arr[right]);
    left++;
    right--;
  }
  return right;
}

void QuickSortBackend(int* arr, int left, int right, bool& reverse) {
  if (left < right) {
    int pivot = Partition(arr, left, right, reverse);
    QuickSortBackend(arr, left, pivot, reverse);
    QuickSortBackend(arr, pivot + 1, right, reverse);
  }
}

void QuickSort(int* arr, int size, bool reverse = false) {
  QuickSortBackend(arr, 0, size - 1, reverse);
}

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  auto* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSort(arr, n, true);
  auto* delta = new int[n - k + 1];
  delta[0] = 0;
  for (int i = 0; i < n - k + 1; i++) {
    delta[i] = arr[i] - arr[i + k - 1];
  }
  QuickSort(delta, n - k + 1);
  std::cout << delta[n % m == 0 ? m - 1 : m - 2];
  delete[] arr;
  delete[] delta;
  return 0;
}