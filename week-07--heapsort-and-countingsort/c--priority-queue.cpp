/*
# C. Приоритетная очередь

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 64Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

Требуется реализовать с помощью пирамиды приоритетную очередь, поддерживающую две операции: добавить элемент и извлечь максимальный элемент. При просеивании нельзя совершать лишние перемещения (например, в случае равенства элементов). Если при просеивании вниз, рассматриваемый элемент можно перемещать как влево вниз, так и вправо вниз, то следует выбрать направление влево.

## Формат ввода

В первой строке вводятся два числа — максимальный размер приоритетной очереди N и количество запросов M, (1 ≤ M,N ≤ 10^5). Далее идут M строк, в каждой строке — по одному запросу. Первое число в запросе задает его тип, остальные числа (если есть) — параметры запроса. Тип 1 — извлечь максимальный (без параметров). Тип 2 — добавить данный элемент в очередь. Запрос имеет один параметр — число из диапазона [-10^9;10^9]

## Формат вывода

В ответ на запрос типа 1 следует вывести: Если извлекать было нечего (очередь пуста), то -1. Иначе — два числа, первое — индекс конечного положения элемента после его просеивания (если удален последний элемент и просеивать нечего то вывести 0), второе — значение извлеченного элемента.

В ответ на запрос типа 2 следует вывести: Если добавить нельзя (нет места, т.к. в очередь уже N элементов), то -1. Иначе — индекс добавленного элемента.

После выполнения всех запросов требуется вывести пирамиду в её конечном состоянии

## Пример

**Ввод**

```
4 7
1
2 9
2 4
2 9
2 9
2 7
1
```

**Вывод**

```
-1
1
2
3
2
-1
2 9
9 4 9
```
 */
#include <iostream>

void SiftUp(int* arr, int id) {
  while (id > 0) {
    int parent = (id - 1) / 2;
    if (arr[parent] < arr[id]) {
      std::swap(arr[parent], arr[id]);
      id = parent;
    } else {
      break;
    }
  }
  std::cout << id + 1 << '\n';
}

void SiftDown(int* arr, int n, int id) {
  while (id < n) {
    int child_1 = id * 2 + 1;
    int child_2 = id * 2 + 2;
    int id_max = id;
    if (child_1 < n && child_2 < n && (arr[child_1] > arr[id_max] || arr[child_2] > arr[id_max])) {
      id_max = (arr[child_1] >= arr[child_2] ? child_1 : child_2);
    } else if (child_1 < n && child_2 >= n && arr[child_1] > arr[id_max]) {
      id_max = child_1;
    }
    if (id_max != id) {
      std::swap(arr[id], arr[id_max]);
      id = id_max;
    } else {
      break;
    }
  }
  std::cout << id + 1 << " ";
}

void ExtractMax(int* arr, int& n) {
  std::swap(arr[0], arr[n - 1]);
  int del = arr[n - 1];
  n -= 1;
  if (n > 0) {
    SiftDown(arr, n, 0);
  } else {
    std::cout << "0 ";
  }
  std::cout << del << '\n';
}

void Push(int*& arr, int& capacity, int element) {
  arr[capacity] = element;
  SiftUp(arr, capacity);
  capacity += 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  auto* arr = new int[n];
  int capacity = 0;
  for (int i = 0; i < m; i++) {
    int command;
    std::cin >> command;
    if (command == 1) {
      if (capacity > 0) {
        ExtractMax(arr, capacity);
      } else {
        std::cout << "-1\n";
      }
    } else {
      int val;
      std::cin >> val;
      if (capacity < n) {
        Push(arr, capacity, val);
      } else {
        std::cout << "-1\n";
      }
    }
  }
  for (int i = 0; i < capacity; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}