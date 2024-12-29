/*
 * D. Заполнение диагоналями с использованием массивов
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Числа по модулю не превышают 2^31 - 1. Даны числа n и m. Выведите таблицу размера n × m, как показано на примере.

Формат ввода
Программа получает на вход два числа n и m (1 ≤ n, m ≤ 100).

Формат вывода
Программа должна вывести числа таблицей. Числа разделяйте одним пробелом.
 */
#include <iostream>

int main() {
  int n, m;
  int count = 0;
  std::cin >> n >> m;

  int **arr = new int *[n];

  for (int i = 0; i < n; i++) {
    arr[i] = new int[m];
  }

  for (int deep = 0; deep < n + m; deep++) {
    for (int row = 0; row < n; row++) {
      if (deep - row >= 0 && deep - row < m) {
        arr[row][deep - row] = count;
        count++;
      }

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
