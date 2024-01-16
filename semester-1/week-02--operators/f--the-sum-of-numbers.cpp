/*
 * F. Сумма чисел
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Вычислите сумму данных N натуральных чисел.

Формат ввода
Вводится число 0 ≤ N ≤ 109, а затем N чисел от 0 до 109, сумму которых необходимо вычислить.

Формат вывода
Выведите единственное число - сумму введенных чисел.
 */
#include <iostream>

int main() {
  int n;
  int sum = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int input;
    std::cin >> input;
    sum += input;
  }
  std::cout << sum;
  return 0;
}