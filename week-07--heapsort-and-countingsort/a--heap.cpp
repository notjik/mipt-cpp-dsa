/*
# A. Пирамида

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 64Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

Реализуйте тип данных «пирамида». Напишите программу, реализовав все указанные здесь методы. Возможные команды для программы:

- «insert n» — Добавить в пирамиду число n (1 ≤ n ≤ 10^9) (значение n задается после команды). Программа должна вывести ok;
- «extract_min» — Удалить из пирамиды минимальный элемент. Программа должна вывести его значение;
- «delete x» Удалить из пирамиды элемент, который был добавлен x-м по счёту командой insert (1 ≤ x ≤ 200000). Программа должна вывести ok;
- «change x n» — Изменить значение элемента, который был добавлен x-м по счёту командой insert (1 ≤ x ≤ 200000) на n (1 ≤ n ≤ 10^9). Программа должна вывести ok.
- «get_min» — Программа должна вывести значение минимального элемента, не удаляя его из пирамиды;
- «size» — Программа должна вывести количество элементов в пирамиде;
- «clear» — Программа должна очистить пирамиду и вывести ok.

Гарантируется, что в каждый момент времени в пирамиде содержатся только различные элементы.

Если во входных данных встречается операция extract_min или get_min, и при этом пирамида пуста, то программа должна вместо числового значения вывести строку error.

Если во входных данных встречается операция delete или change, и при этом соответствующего элемента x в пирамиде нет, то программа должна вместо ok вывести строку error.

## Формат ввода

В первой строке входных данных записано единственное число M (1 ≤ M ≤ 200000) — количество команд. В следующих М строках дано по одной команде из тех, что идут выше.

## Формат вывода

Для каждой команды выведите одну строчку — результат ее выполнения.

## Пример

**Ввод**

```
20
insert 18
extract_min
insert 3
extract_min
insert 10
extract_min
insert 14
insert 20
insert 11
delete 6
extract_min
insert 8
get_min
insert 9
change 7 12
change 4 5
insert 13
change 5 16
insert 19
insert 7
```

**Вывод**

```
ok
18
ok
3
ok
10
ok
ok
ok
ok
14
ok
8
ok
ok
error
ok
ok
ok
ok
```
 */
#include <cstring>
#include <iostream>

struct Heap {
  int* _array;
  int* _insertion_order;
  int _size = 0;
  int _capacity;

  explicit Heap(int capacity) {
    _capacity = capacity;
    _array = new int[_capacity];
    _insertion_order = new int[_capacity];
  }

  ~Heap() {
    delete[] _array;
    delete[] _insertion_order;
  }

  int LeftChild(int index) {
    return 2 * index + 1;
  }

  int RightChild(int index) {
    return 2 * index + 2;
  }

  void SiftUp(int i) {
    while (i > 0 && _array[(i - 1) / 2] > _array[i]) {
      std::swap(_array[i], _array[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }

  void SiftDown(int i) {
    int left = LeftChild(i);
    int right = RightChild(i);
    int smallest = i;

    if (left < _size && _array[left] < _array[i]) {
      smallest = left;
    }

    if (right < _size && _array[right] < _array[smallest]) {
      smallest = right;
    }

    if (smallest != i) {
      std::swap(_array[i], _array[smallest]);
      SiftDown(smallest);
    }
  }

  int Find(int val) {
    for (int i = 0; i < _size; i++) {
      if (_array[i] == val) {
        return i;
      }
    }
    return -1;
  }

  void Insert(int n) {
    _array[_size] = n;
    _insertion_order[_size] = n;
    SiftUp(_size);
    _size++;
    std::cout << "ok" << std::endl;
  }

  void ExtractMin() {
    if (_size == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    int result = _array[0];
    _array[0] = _array[_size - 1];
    _size--;
    if (_size > 0) {
      SiftDown(0);
    }
    std::cout << result << std::endl;
  }

  void Delete(int x) {
    if (_size == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    int index = Find(_insertion_order[x - 1]);
    _array[index] = _array[_size - 1];
    _size--;
    SiftDown(index);
    std::cout << "ok" << std::endl;
  }

  void Change(int x, int n) {
    int index = Find(_insertion_order[x - 1]);
    if (index == -1) {
      std::cout << "error" << std::endl;
      return;
    }
    _array[index] = n;
    SiftDown(index);
  }

  void GetMin() {
    if (_size == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    std::cout << _array[0] << std::endl;
  }

  void Size() {
    std::cout << _size << std::endl;
  }

  void Clear() {
    _size = 0;
    std::cout << "ok" << std::endl;
  }
};

int main() {
  int m1;
  std::cin >> m1;
  const int m = m1;
  auto* heap = new Heap(m);
  char str[12];
  for (int i = 0; i < m; i++) {
    std::cin >> str;
    if (!strcmp(str, "insert")) {
      int n;
      std::cin >> n;
      heap->Insert(n);
    } else if (!strcmp(str, "extract_min")) {
      heap->ExtractMin();
    } else if (!strcmp(str, "delete")) {
      int x;
      std::cin >> x;
      heap->Delete(x);
    } else if (!strcmp(str, "change")) {
      int x, n;
      std::cin >> x >> n;
      heap->Change(x, n);
    } else if (!strcmp(str, "get_min")) {
      heap->GetMin();
    } else if (!strcmp(str, "size")) {
      heap->Size();
    } else if (!strcmp(str, "clear")) {
      heap->Clear();
    }
  }
  delete heap;
  return 0;
}
