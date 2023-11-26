/*
 * D. Трубочист

**Ограничение времени:** 10 секунд
**Ограничение памяти:** 256Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

После пожара 1812 года на одной из главных улиц Москвы уцелел лишь один дом. Вернувшиеся после победы жители решили вновь поселиться на этой улице. При этом каждый решил построить себе дом такой же высоты, каким он был у него до пожара.

Дома будут строиться вплотную друг другу, а крыши соседних домов будут соединяться лестницами (длина лестницы равна разнице высот домов), чтобы трубочист мог путешествовать по крышам и чистить трубы.

Когда план постройки домов был уже почти утвержден, свое веское слово сказал Главный Трубочист. Он попросил построить дома так, чтобы суммарная длина лестниц была минимальной. Помогите ему составить такой план постройки домов.

**Формат ввода**
Во входном файле записано сначала число N (1 ≤ N ≤ 10000), затем N чисел — высоты домов до пожара (это натуральные числа от 1 до 10^9), и затем K — номер уцелевшего дома.

**Формат вывода**
В выходной файл выведите высоты домов в таком порядке, чтобы выполнялось требование Главного Трубочиста. Обратите внимание, что K-ый дом (уцелевший) перестраивать не нужно (и следовательно его высота должна остаться прежней).

**Пример**
**Ввод:**
```
5
1 3 4 2 6
2
```
**Вывод:**
```
1 2 3 4 6
```

**Объяснение:**

В данном примере нужно распределить высоты домов [1, 3, 4, 2, 6] в таком порядке, чтобы минимизировать суммарную длину лестниц. Уцелевший дом имеет высоту 2 (K=2). Оптимальное распределение высот домов, минимизирующее длину лестниц, будет [1, 2, 3, 4, 6].
 */
#include <iostream>

int Max(const int* arr, int left, int right) {
  int max = -1;
  for (int i = left; i <= right; i++) {
    max = (max < arr[i] ? arr[i] : max);
  }
  return max;
}

int Min(const int* arr, int left, int right) {
  int min = 1000000;
  for (int i = left; i <= right; i++) {
    min = (min > arr[i] ? arr[i] : min);
  }
  return min;
}

int Partition(int* arr, int left, int right, const bool& reverse = false) {
  int pivot = arr[left];
  int i = left + 1;
  int j = right;
  while (true) {
    while (i <= j && (reverse ? arr[i] >= pivot : arr[i] <= pivot)) {
      i++;
    }
    while (j >= i && (reverse ? arr[i] <= pivot : arr[j] >= pivot)) {
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

void QuickSortBackend(int* arr, int left, int right,
                      const bool& reverse = false) {
  if (left < right) {
    int pivot_index = Partition(arr, left, right, reverse);
    QuickSortBackend(arr, left, pivot_index - 1, reverse);
    QuickSortBackend(arr, pivot_index + 1, right, reverse);
  }
}

void QuickSort(int* arr, int size, bool reverse = false) {
  QuickSortBackend(arr, 0, size - 1, reverse);
}

int main() {
  int n, k;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::cin >> k;
  if (k - 2 >= 0) {
    bool reverse1 = abs(Max(arr, 0, k - 2) - arr[k - 1]) >
                    abs(Min(arr, 0, k - 2) - arr[k - 1]);
    QuickSortBackend(arr, 0, k - 2, reverse1);
  }
  if (k <= n - 1) {
    bool reverse2 = abs(Max(arr, k, n - 1) - arr[k - 1]) <
                    abs(Min(arr, k - 2, n - 1) - arr[k - 1]);
    QuickSortBackend(arr, k, n - 1, reverse2);
  }
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }
  delete[] arr;
}
