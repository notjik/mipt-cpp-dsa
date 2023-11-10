/*
 * G. Двоичный поиск
Ограничение времени	1.5 секунд
Ограничение памяти	256Mb
Ввод	стандартный ввод
Вывод	стандартный вывод
Реализуйте алгоритм бинарного поиска.

Формат ввода
В первой строке входных данных содержатся натуральные числа N и K (0<N,K≤ 105). Во второй строке задаются N элементов первого массива, отсортированного по возрастанию, а в третьей строке — K элементов второго массива. Элементы обоих массивов - целые числа, каждое из которых по модулю не превосходит 109.

Формат вывода
Требуется для каждого из K чисел вывести в отдельную строку «YES», если это число встречается в первом массиве, и «NO» в противном случае.

Примечания
Используйте в этой и последующей задачах быстрый ввод. */
#include <iostream>

bool BinarySearch(const int *arr, int left, int right, int target) {
  bool find = false;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      find = true;
      break;
    }
    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return find;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < k; i++) {
    int target;
    std::cin >> target;
    std::cout << (BinarySearch(arr, 0, n - 1, target) ? "YES" : "NO") << '\n';
  }

  delete[] arr;
  return 0;
}