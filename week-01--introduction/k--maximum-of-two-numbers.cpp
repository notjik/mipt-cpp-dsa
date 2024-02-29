/*
 * K. Максимум из двух чисел
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Даны два целых числа, каждое число записано в отдельной строке. Выведите наибольшее из данных чисел.

Формат ввода
На вход подаются 2 числа не большие 10000.

Формат вывода
Единственное число – искомый ответ.
 Примечания
При решении этой задачи нельзя пользоваться условной инструкцией if и циклами.
 */
#include <iostream>

int AbsFunc(int n) {
  return n * ((2 * n + 1) % 2);
}

int main() {
  int a;
  int b;
  std::cin >> a >> b;
  std::cout << (a + b + AbsFunc(a - b)) / 2;
  return 0;
}