/*
 * F. Спираль
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Требуется заполнить массив размера N×N единичками по спирали (начиная с верхнего левого угла по часовой стрелке, см. пример).
Формат ввода
С клавиатуры вводится число N (нечетное, натуральное и не превышающее 50).
Формат вывода
Требуется вывести на экран построенную спираль.
 */
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int **arr = new int *[n];

  for (int i = 0; i < n; i++) {
    arr[i] = new int[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }

  int x = 0, y = 0, queue = 0;
  for (int i = 0; i < n * n; i++) {
    arr[x][y] = 1;
    if (queue % 4 == 0) {
      y++;
      if (y >= n || (y + 1 < n && arr[x][y + 1] == 1)) {
        queue++;
        y--;
      }
    }
    if (queue % 4 == 1) {
      x++;
      if (x >= n || (x + 1 < n && arr[x + 1][y] == 1)) {
        queue++;
        x--;
      }
    }
    if (queue % 4 == 2) {
      y--;
      if (y < 0 || (y - 1 >= 0 && arr[x][y - 1] == 1)) {
        queue++;
        y++;
      }
    }
    if (queue % 4 == 3) {
      x--;
      if (x < 0 || (x - 1 >= 0 && arr[x - 1][y] == 1)) {
        queue = 0;
        x++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j];
    }
    std::cout << '\n';
  }

  for (int i = 0; i < n; i++) {
    delete[] arr[i];
  }

  delete[] arr;
  return 0;
}
