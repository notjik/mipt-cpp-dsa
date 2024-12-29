/*
 * D. Периметр треугольника
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Напишите функцию, вычисляющую длину отрезка по координатам его концов. С помощью этой функции напишите программу, вычисляющую периметр треугольника по координатам трех его вершин.
Формат ввода
На вход программе подается 6 целых чисел — координат x1,y1,x2,y2,x3,y3 вершин треугольника. Все числа по модулю не превосходят 10^9.
Формат вывода
Выведите значение периметра этого треугольника с точностью ровно 6 знаков после десятичной точки.
 */
#include <iostream>
#include <cmath>
#include <iomanip>

double PowToSqrt(double x) {
  return x * x;
}

double LenLine(double x1, double y1, double x2, double y2) {
  return sqrtf(PowToSqrt(x2 - x1) + PowToSqrt(y2 - y1));
}

int main() {
  double x1, y1, x2, y2, x3, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  std::cout << std::fixed << std::setprecision(6);
  std::cout << LenLine(x1, y1, x2, y2) + LenLine(x2, y2, x3, y3) + LenLine(x1, y1, x3, y3);
  return 0;
}
