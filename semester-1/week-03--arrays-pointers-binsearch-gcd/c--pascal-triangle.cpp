/*
 * C. Треугольник Паскаля
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Даны два числа n и m. Создайте двумерный массив [n][m] и заполните его по следующим правилам: Числа, стоящие в строке 0 или в столбце 0 равны 1 (A[0][j]=1, A[i][0]=1). Для всех остальных элементов массива A[i][j]=A[i-1][j]+A[i][j-1], то есть каждый элемент равен сумме двух элементов, стоящих слева и сверху от него.
Формат ввода
Программа получает на вход два числа n < 100 и m < 100.
Формат вывода
Выведите данный массив.
 */
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  int **arr = new int *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[m];
  }

  for (int i = 0; i < n; i++) {
    arr[i][0] = 1;
  }
  for (int j = 0; j < m; j++) {
    arr[0][j] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << '\n';
  }

  for (int i = 0; i < n; i++) {
    delete[] arr[i];
  }
  delete[] arr;

  return 0;
}
