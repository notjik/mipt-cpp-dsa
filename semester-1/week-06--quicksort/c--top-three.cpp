/*
 * **C. Трое лучших**

**Ограничение времени:** 1 секунда

**Ограничение памяти:** 256 Мб

**Ввод:** стандартный ввод или input.txt

**Вывод:** стандартный вывод или output.txt

Определите троих учащихся с наилучшим средним баллом по трем предметам. Выведите фамилии и имена этих учащихся. Если при этом у нескольких учащихся средний балл совпадает со средним баллом учащегося, "занявшего 3-е место", то необходимо вывести их всех.

**Формат ввода:**

Заданы сначала количество учащихся n, затем n строк, каждая из которых содержит фамилию, имя и три числа (оценки по трем предметам: математике, физике, информатике). Данные в строке разделены одним пробелом. Оценки принимают значение от 1 до 5. Фамилия и имя имеют длину не более 1000 символов.

**Формат вывода:**

Необходимо вывести пары фамилия-имя по одной на строке, разделяя фамилию и имя одним пробелом. Выводить оценки не нужно. Порядок вывода должен быть таким же, как в исходных данных.

**Пример 1:**

**Ввод:**
```
3
Team Spirit 5 5 5
PSG LGD 3 3 3
Team Secret 2 2 2
```

**Вывод:**
```
Team Spirit
PSG LGD
Team Secret
```

**Пример 2:**

**Ввод:**
```
3
Yakovlev Ivan 5 5 5
Yapryntsev Aleksey 5 5 5
Kozlov Georgiy 5 5 5
```

**Вывод:**
```
Yakovlev Ivan
Yapryntsev Aleksey
Kozlov Georgiy
```
 */
#include <iostream>

int PartitionHoar(int** arr, int left, int right) {
  int mid = (left + right) / 2;
  int pivot = arr[mid][1] + arr[mid][2] + arr[mid][3];
  while (left < right) {
    while (arr[left][1] + arr[left][2] + arr[left][3] > pivot) {
      left++;
    }
    while (arr[right][1] + arr[right][2] + arr[right][3] < pivot) {
      right--;
    }
    if (left >= right) {
      break;
    }
    int* temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    left++;
    right--;
  }
  return right;
}

void QuickSortHoar(int** arr, int left, int right) {
  if (left < right) {
    int pivotIndex = PartitionHoar(arr, left, right);
    QuickSortHoar(arr, left, pivotIndex);
    QuickSortHoar(arr, pivotIndex + 1, right);
  }
}

int main() {
  int n;
  std::cin >> n;
  char** surname = new char* [n];
  char** name = new char* [n];
  int** start_table = new int* [n];
  int** table = new int* [n];
  for (int i = 0; i < n; i++) {
    surname[i] = new char[1001];
    name[i] = new char[1001];
    table[i] = new int[4];
    table[i][0] = i;
    std::cin >> surname[i] >> name[i] >> table[i][1] >> table[i][2] >>
             table[i][3];
    start_table[i] = new int[4];
    start_table[i][0] = table[i][0];
    start_table[i][1] = table[i][1];
    start_table[i][2] = table[i][2];
    start_table[i][3] = table[i][3];
  }
  QuickSortHoar(table, 0, n - 1);
  int sum3 = table[2][1] + table[2][2] + table[2][3];
  for (int i = 0; i < n; i++) {
    int sum = start_table[i][1] + start_table[i][2] + start_table[i][3];
    if (sum >= sum3) {
      std::cout << surname[start_table[i][0]] << ' ' << name[start_table[i][0]];
      std::cout << '\n';
    }
  }
  for (int i = 0; i < n; i++) {
    delete[] surname[i];
    delete[] name[i];
    delete[] start_table[i];
    delete[] table[i];
  }
  delete[] surname;
  delete[] name;
  delete[] start_table;
  delete[] table;
}