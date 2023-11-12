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
#include <cstdint>
#include <iostream>

int64_t Partition(int64_t* arr, int64_t left, int64_t right, const bool& reverse) {
  int64_t mid = (left + right) / 2;
  int64_t pivot = arr[mid];
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

void QuickSortBackend(int64_t* arr, int64_t left, int64_t right, const bool& reverse) {
  if (left < right) {
    int64_t pivot = Partition(arr, left, right, reverse);
    QuickSortBackend(arr, left, pivot, reverse);
    QuickSortBackend(arr, pivot + 1, right, reverse);
  }
}

void QuickSort(int64_t* arr, int64_t size, bool reverse = false) {
  QuickSortBackend(arr, 0, size - 1, reverse);
}

int64_t Groups(const int64_t* arr, int64_t size, int64_t left, int64_t right, int64_t k) {
  int64_t mid = (left + right) / 2;
  int64_t groups = 0;
  for (int64_t i = 0; i < size - k + 1; i++) {
    if (arr[i + k - 1] - arr[i] <= mid) {
      groups++;
      i += k - 1;
    }
  }
  return groups;
}

int main() {
  int64_t n, m, k;
  std::cin >> n >> m >> k;
  auto* arr = new int64_t[n];
  for (int64_t i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSort(arr, n);
  int64_t left = 0;
  int64_t right = arr[n - 1] - arr[0];
  while (left < right - 1) {
    int64_t groups = Groups(arr, n, left, right, k);
    if (groups >= m) {
      right = (left + right) / 2;
    } else {
      left = (left + right) / 2;
    }
  }
  int64_t groups = Groups(arr, n, left, right, k);
  if (groups == m) {
    std::cout << left;
  } else {
    std::cout << right;
  }
  delete[] arr;
  return 0;
}