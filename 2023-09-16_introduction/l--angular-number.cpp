/*
 * L. Четное число
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Путь четности самурая начинается с первого шага – определить является ли число четным.

Формат ввода
Вводится одно число.

Формат вывода
Выведите "YES", если да, "NO", если нет.
 Примечания
Friendly reminder: при решении можно использовать только арифметические операции (+, -, *, /, %) и условные конструкции.
 */
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << ((n % 2 == 0) ? "YES" : "NO");
  return 0;
}
