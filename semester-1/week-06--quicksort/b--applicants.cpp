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

int64_t Partition(int64_t* arr, int64_t left, int64_t right) {
  int64_t pivot = arr[left];
  int64_t i = left + 1;
  int64_t j = right;
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

void QuickSortBackend(int64_t* arr, int64_t left, int64_t right) {
  if (left < right) {
    int64_t pivot_index = Partition(arr, left, right);
    QuickSortBackend(arr, left, pivot_index - 1);
    QuickSortBackend(arr, pivot_index + 1, right);
  }
}

void QuickSort(int64_t* arr, int64_t size) {
  QuickSortBackend(arr, 0, size - 1);
}

int64_t Groups(const int64_t* arr, int64_t size, int64_t mid, int64_t k) {
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
    int64_t mid = left + (right - left) / 2;
    int64_t groups = Groups(arr, n, mid, k);
    if (groups >= m) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  if (Groups(arr, n, left, k) >= m) {
    std::cout << left;
  } else {
    std::cout << right;
  }
  delete[] arr;
  return 0;
}