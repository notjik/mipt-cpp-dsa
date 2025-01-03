/*
 * J. Проверьте делимость
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Даны два натуральных числа n и m. Если одно из них делится на другое нацело, выведите 1, иначе выведите любое другое целое число.

При решении можно использовать только арифметические операции (+, -, *, /, %) и abs из библиотеки cmath или math.h. Пользоваться условными операторами, циклами. массивами, логическими сравнениями и приведением типов запрещено.

Формат ввода
Вводятся два натуральных числа n и m.

Формат вывода
Выведите ответ на задачу.
 */
#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  bool try1 = n % m == 0;
  bool try2 = m % n == 0;
  std::cout << (try1 || try2);
  return 0;
}