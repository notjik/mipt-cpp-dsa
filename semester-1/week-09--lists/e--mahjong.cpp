/*
# E. Маджонг

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 256Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

Петя недавно узнал о существовании игры маджонг. Она ему показалась настолько интересной, что он играет в нее целыми днями. Для этой игры необходима прямоугольная доска размером m × n полей и набор фишек разных цветов. При этом фишек каждого цвета в наборе должно быть ровно две. В начале игры фишки располагаются на доске произвольным образом.

После этого за один ход разрешается снять пару фишек одного цвета, если они обе являются самыми правыми в своих горизонталях, либо самыми левыми в своих горизонталях, либо самыми нижними в своих вертикалях, либо самыми верхними в своих вертикалях. Если соответствующей пары фишек нет, то игра закончена.

Цель игры состоит в том, чтобы сделать как можно больше ходов.

Задана начальная расстановка фишек на доске. Требуется найти самую длинную последовательность ходов, которую может сделать Петя из заданной позиции.

## Формат ввода

Первая строка входного файла содержит размеры доски: два целых числа m и n (1 ≤ m, n ≤ 300, хотя бы одно из этих чисел четно). Далее следуют m строк по n чисел в каждой, j-е число в i-й из этих строк представляет собой номер цвета j-й слева фишки в i-й горизонтали. Цвета пронумерованы натуральными числами от 1 до n*m / 2. На доске ровно две фишки каждого цвета.

## Формат вывода

В первой строке выходного файла выведите k — максимальное количество ходов, которое может сделать Петя из заданной начальной позиции. Во второй строке выходного файла выведите разделенные пробелами k чисел — номера цветов фишек в том порядке, в котором они должны сниматься с доски. Если возможных ответов несколько, выведите любой.
 */