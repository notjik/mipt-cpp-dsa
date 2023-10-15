/*
 * L. Побочная диагональ
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Дано число n, оно задает размер таблицы n × n. Выведите числа таблицей по следующему правилу:

- числа на диагонали, идущей из правого верхнего в левый нижний угол, равны 1;

- числа, стоящие выше этой диагонали, равны 0;

- числа, стоящие ниже этой диагонали, равны 2.

Формат ввода
Программа получает на вход число n (n < 100).

Формат вывода
Необходимо вывести таблицу. Числа разделяйте одним пробелом.
 */
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (n - j - 1 > i) {
        std::cout << '0' << ' ';
      } else if (n - j - 1 == i) {
        std::cout << '1' << ' ';
      } else {
        std::cout << '2' << ' ';
      }
    }
    std::cout << '\n';
  }
  return 0;
}
