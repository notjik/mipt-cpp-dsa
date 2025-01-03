/*
 * B. Без массивов
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Дано натуральное число N и последовательность из N элементов. Требуется вывести эту последовательность в обратном порядке.

Формат ввода
В первой строке входных данных содержится натуральное число N (1 ≤ N ≤ 103).

Во второй строке через пробел идут N целых чисел, по модулю не превосходящих 1000, – элементы последовательности.

Формат вывода
Требуется вывести заданную последовательность в обратном порядке.

Примечания
В программе запрещается объявлять массивы и использовать циклы (даже для ввода и вывода).
 */
#include <iostream>

void Func(int n) {
  if (n > 0) {
    int num;
    std::cin >> num;
    Func(--n);
    std::cout << num << ' ';
  }
}

int main() {
  int n;
  std::cin >> n;
  Func(n);
}