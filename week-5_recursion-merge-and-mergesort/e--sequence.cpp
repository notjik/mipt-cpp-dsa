/*
 * E. Последовательность
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Последовательность 011212201220200112... строится так:

сначала пишется 0, затем повторяется следующее действие: уже написанную часть приписывают справа с заменой 0 на 1, 1 на 2, 2 на 0, т.е.:

 0 -> 01 -> 0112 -> 01121220 -> ...

Составить алгоритм, который по введенному k определяет, какое число стоит на k-ом месте в последовательности.

Формат ввода
Дано натуральное число k (1 ≤ k ≤ 1018).

Формат вывода
Выведите число, которое стоит на k-ом месте в последовательности.
 */