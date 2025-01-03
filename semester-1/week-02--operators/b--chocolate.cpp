/*
 * B. Шоколадка
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Требуется определить, можно ли от шоколадки размером n × m долек отломить k долек, если разрешается сделать один разлом по прямой между дольками (то есть разломить шоколадку на два прямоугольника).

Формат ввода
Вводятся 3 числа: n, m и k, причем k не равно n × m. Гарантируется, что количество долек в шоколадке не превосходит 40000.

Формат вывода
Программа должна вывести слово YES, если возможно отломить указанное число долек, в противном случае вывести слово NO.

Friendly reminder: при решении можно использовать только арифметические операции (+, -, *, /, %) и и условные конструкции.
 */
#include <iostream>

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::cout << ((k % n == 0 || k % m == 0) && k < m * n ? "YES" : "NO");
  return 0;
}
