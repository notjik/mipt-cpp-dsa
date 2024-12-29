/*
 * E. Сапер
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Напишите программу, отображающую игровое поле для игры "Сапер".
Формат ввода
Даны числа N и M (целые, положительные, не превышают 32) – количество строк и столбцов в поле соответственно, далее число W (целое, неотрицательное, не больше 1000) – количество мин на поле, далее следует W пар чисел, координаты мины на поле (первое число – строка, второе число – столбец).
Формат вывода
Требуется вывести на экран поле. Формат вывода указан в примере.
 */
#include <iostream>

int main() {
  int rows, cols, mines;
  std::cin >> rows >> cols >> mines;
  cols += 2;
  rows += 2;
  int **field = new int *[rows];
  for (int i = 0; i < rows; i++) {
    field[i] = new int[cols];
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      field[i][j] = 0;
    }
  }
  for (int i = 0; i < mines; i++) {
    int x, y;
    std::cin >> x >> y;
    field[x][y] = -1;
    for (int a = x - 1; a <= x + 1; a++) {
      for (int b = y - 1; b <= y + 1; b++) {
        if (field[a][b] != -1) {
          field[a][b]++;
        }
      }
    }
  }

  for (int i = 1; i < rows - 1; i++) {
    for (int j = 1; j < cols - 1; j++) {
      if (field[i][j] == -1) {
        std::cout << '*' << ' ';
      } else {
        std::cout << field[i][j] << ' ';
      }
    }
    std::cout << '\n';
  }

  for (int i = 0; i < rows; i++) {
    delete[] field[i];
  }

  delete[] field;

  return 0;
}