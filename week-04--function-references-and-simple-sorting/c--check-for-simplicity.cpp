/*
 * C. Проверка на простоту
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Напишите функцию, проверяющую является ли число простым.
Формат ввода
Вводится одно натуральное число не превышающее 2000000000 и не равное 1.
Формат вывода
Необходимо вывести строку prime, если число простое, или composite, если число составное.
 */
#include <iostream>
#include <cinttypes>

bool IsPrime(uint64_t number) {
  uint64_t i = 2;
  while (i * i <= number) {
    if (number % i == 0) {
      break;
    }
    i++;
  }
  return i * i > number;
}

int main() {
  uint64_t number;
  std::cin >> number;
  std::cout << (IsPrime(number) ? "prime" : "composite");
  return 0;
}
