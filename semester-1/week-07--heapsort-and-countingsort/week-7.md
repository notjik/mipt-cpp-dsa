```cpp
// Включение необходимых заголовочных файлов для работы с потоками ввода-вывода и целочисленными типами.
#include <iostream>
#include <cstdint>

// Функция для вычисления индекса левого дочернего элемента в куче для заданного индекса "index".
int64_t LeftChild(int64_t index) {
return 2 * index + 1;
}

// Функция для вычисления индекса правого дочернего элемента в куче для заданного индекса "index".
int64_t RightChild(int64_t index) {
return 2 * index + 2;
}

// Функция для вычисления индекса родительского элемента в куче для заданного индекса "index".
int64_t Parent(int64_t index) {
return (index - 1) / 2;
}

void SiftDown(int* begin, int* end, int64_t i) {
  // Определение размера подмассива для работы и вычисление его текущей длины.
  int _size = end - begin;

  while (i < _size) {
    // Инициализация индекса текущих элементов.
    int left_child = LeftChild(i);
    int right_child = RightChild(i);
    int id_max = i;
    
    // Если левый дочерний элемент существует и больше текущего максимального, обновляем индекс максимального.
    if (left_child < _size && *(begin + left_child) > *(begin + id_max)) {
      id_max = left_child;
    }

    // Если правый дочерний элемент существует и больше текущего максимального, обновляем индекс максимального.
    if (right_child < _size && *(begin + right_child) > *(begin + id_max)) {
      id_max = right_child;
    }

    // Если текущий элемент не максимальный, меняем его местами с максимальным и обновляем индекс.
    if (i != id_max) {
      std::swap(*(begin + i), *(begin + id_max));
      i = id_max;
    }
    // Иначе завершаем процесс просеивания, так как свойство кучи восстановлено.
    else {
      break;
    }
  }
}

void BuildHeap(int* begin, int* end) {
  // Определение размера массива исходных данных.
  int _size = end - begin;

  // Перебираем элементы массива, начиная с середины и идя к началу.
  for (int i = (_size - 1) / 2; i >= 0; i--) {
    // Применяем процедуру просеивания для каждого элемента, чтобы построить кучу.
    SiftDown(begin, end, i);
  }
}

void HeapSort(int* begin, int* end) {
  // Определение размера массива.
  int _size = end - begin;

  // Строим кучу из массива.
  BuildHeap(begin, end);

  for (int i = _size - 1; i > 0; i--) {
    // Обмениваем максимальный элемент с последним элементом в массиве.
    std::swap(*(begin), *(begin + i));

    // Уменьшаем размер кучи и восстанавливаем свойство кучи.
    SiftDown(begin, --end, 0);
  }
}

int main() {
  int n;
  std::cin >> n;
  // Вводим количество элементов в массиве.

  int* arr_ = new int[n];
  // Выделяем память для массива.

  for (int i = 0; i < n; i++) {
    std::cin >> arr_[i];
    // Заполняем массив введенными значениями.
  }

  HeapSort(arr_, arr_ + n);
  // Сортируем массив с использованием алгоритма HeapSort.

  // Выводим отсортированные значения.
  for (int i = 0; i < n; i++) {
    std::cout << arr_[i] << ' ';
  }
  
  delete[] arr_;
  return 0;
  // Завершаем программу.
}
```