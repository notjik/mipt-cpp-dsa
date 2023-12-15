/*
# G. Задача о рюкзаке

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 64Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

Как известно, программисты люди не очень активные. Тем не менее иногда они выходят из своих подземных занавешенных туннелей на свободу и идут в поход. Им это очень нравится, тем не менее зачастую хочется взять больше, чем можно на себе унести. Давайте поможем отважным походникам собрать их рюкзак.

Мы хотим взять как можно больше предметов, тем не менее не перегрузив спину программиста (она ему еще понадобится!).

## Формат ввода

Сначала вводится одно число - максимальный вес, который может утащить программист. Далее вводится число N - количество предметов, из которых он будет выбирать себе вещи в поход. На следующих N строках вводятся числа - веса предметов, которые программист имеет возможность взять с собой.

## Формат вывода

Два числа через пробел – максимальное количество предметов, которые может взять программист. Второе число - максимально возможный суммарный вес этих предметов.

## Пример

**Ввод**

```
100
10
31
35
46
49
54
79
82
93
99
99
```

**Вывод**

```
2 85
```

## Примечания

Найдите приблизительный максимальный суммарный вес предметов, использовав алгоритм со временем выполнения не более, чем O(nlogn).
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
  int weight, n;
  std::cin >> weight >> n;
  int* backpack = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> backpack[i];
  }
  QuickSort(backpack, n);
  int i = 0;
  int add = 0;
  while (i < n && add + backpack[i] <= weight) {
    add += backpack[i];
    i++;
  }
  std::cout << i << ' ';
  i--;
  add -= backpack[i];
  while (i < n && add + backpack[i] <= weight) {
    i++;
  }
  i--;
  std::cout << backpack[i] + add << '\n';
  delete[] backpack;
}