/*
 * C. Быстрое возведение в степень
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Напишите функцию быстрого возведения в степень. Количество действий должно быть пропорционально двоичному логарифму n.

Формат ввода
Вводится 2 числа - a (вещественное) и n (0 ≤ n ≤ 109).

Формат вывода
Необходимо вывести значение a^n.
 */
#include <iostream>

long double Pow(double a, int n) {
  if (n == 0) {
    return 1;
  }
  if (n < 0) {
    return 1 / Pow(a, -n);
  }
  if (n % 2 == 0) {
    long double half = Pow(a, n / 2);
    return half * half;
  }
  return a * Pow(a, n - 1);
}

int main() {
  long double a;
  int n;
  std::cin >> a >> n;
  std::cout << Pow(a, n);
}
