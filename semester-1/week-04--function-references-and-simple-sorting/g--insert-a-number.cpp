/*
 * G. Вставка числа
Ограничение времени	1 секунда
Ограничение памяти	256.0 Мб
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Требуется вставить в данный массив на данное место данный элемент, сдвинув остальные элементы вправо.

Формат ввода
В первой строке вводится одно натуральное число n (0<n≤100) ~--- размер массива.

Во второй строке задаются n чисел -- элементы массива (целые числа, не превосходящие по модулю 1000).

В третьей строке вводится число, которое необходимо вставить, и номер места, на которое его нужно вставить.

Формат вывода
Вывести получившийся массив.
 */
#include <iostream>

void Insertion(int *arr, const int size, const int elem, const int insert_index) {
  int j = size - 1;
  while (j >= insert_index) {
    arr[j + 1] = arr[j];
    j--;
  }
  arr[j + 1] = elem;
}

int main() {
  int size;
  std::cin >> size;
  int *arr = new int[size + 1];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  int elem, insert_index;
  std::cin >> elem >> insert_index;
  Insertion(arr, size++, elem, --insert_index);
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}
