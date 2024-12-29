/*
 * E. Минимальный делитель
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Найдите самый маленький натуральный делитель числа x.

Формат ввода
Вводится натуральное число 2 ≤ x ≤ 109.

Формат вывода
Выведите наименьший делитель числа x, отличный от 1.
 */
#include <iostream>

int main() {
  int num;
  std::cin >> num;
  for (int i = 2; i <= num; i++) {
    if (num % i == 0) {
      std::cout << i;
      break;
    }
  }
  return 0;
}
