/*
 * H. НОД и НОК
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Вычислите НОД и НОК двух чисел.

Формат ввода
На вход подается два числа x, y через пробел. 0 < x, y < 231 - 1

Формат вывода
Выведите два числа, разделенных через пробел: НОД(x, y) и НОК(x, y).

Примечания
Запрещено использовать std::gcd и std::lcm для решения данной задачи.
 */
#include <iostream>
#include <cstdint>

uint64_t GCD(uint64_t a, uint64_t b) {
  while (a * b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

int main() {
  int64_t a, b;
  std::cin >> a >> b;
  int64_t gcd_a_b = GCD(a, b);
  std::cout << gcd_a_b << ' ' << a * b / gcd_a_b;
  return 0;
}
