/*
 * I. Улитка
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Улитка ползёт по вертикальному шесту высотой h метров, поднимаясь за день на a метров, а за ночь спускаясь на b метров. На какой день улитка доползёт до вершины шеста? При решении этой задачи нельзя пользоваться условной инструкцией if и циклами.

Формат ввода
Программа получает на вход натуральные числа h, a, b. Гарантируется, что a>b.

Формат вывода
Программа должна вывести одно натуральное число.
 Примечания
При решении этой задачи нельзя пользоваться условной инструкцией if и циклами.
 */
#include <iostream>

int main() {
  int h, a, b;
  std::cin >> h >> a >> b;
  std::cout << (h - b - 1) / (a - b) + 1;
  return 0;
}
