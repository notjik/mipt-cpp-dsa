/*
 * H. Разность времен
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Даны значения двух моментов времени, принадлежащих одним и тем же суткам: часы, минуты и секунды для каждого из моментов времени. Известно, что второй момент времени наступил не раньше первого. Определите, сколько секунд прошло между двумя моментами времени.
Формат ввода
Программа на вход получает три целых числа — часы, минуты, секунды, задающие первый момент времени и три целых числа, задающих второй момент времени.
Формат вывода
Выведите число секунд между этими моментами времени.
 */
#include <iostream>

int main() {
  int time1, time2;
  int h, m, s;
  std::cin >> h >> m >> s;
  time1 += h * 60 * 60 + m * 60 + s;
  std::cin >> h >> m >> s;
  time2 += h * 60 * 60 + m * 60 + s;
  std::cout << time2 - time1;
}
