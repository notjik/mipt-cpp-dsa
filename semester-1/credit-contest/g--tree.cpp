/*
# G(4). TREE [АиСД-23]

Ограничение времени: 1 секунда
Ограничение памяти: 256.0 Мб
Ввод: стандартный ввод или input.txt
Вывод: стандартный вывод или output.txt

## Медведь на дереве

Как же я жила без пианина; И как же я без музыки жила?

Маша бегала-бегала за Мишкой, а он все не находился, ведь он сидел на дереве и преспокойно читал газету. В результате Маша нашла утешение в программировании и реализовала свое бинарное дерево поиска. Во Маша может!

Повторите путь Маши, напишите бинарное дерево поиска. Вам передадут значения узлов (вершин) этого дерева.

Проверьте, является ли описанное в примере дерево корректным бинарным деревом поиска, или нет.

## Формат ввода

В первой строчке записано целое число N - количество вершин в дереве.

Вершины дерева пронумерованы числами от 0 до N-1.

Вершина 0 является корнем. Каждая из следующих N строк содержит информацию о вершинах 0, 1, …, N-1:

i-я строка задаёт числа key_i, left_i и right_i, где
key_i --- ключ вершины i,
left_i --- индекс левого сына вершины i,
right_i --- индекс правого сына вершины i.
Если у вершины i нет одного или обоих сыновей, соответствующее значение равно -1.

А еще мы знаем, что: 1 ≤ N < 2^10; -2^31 < key_i < 2^31 - 1; -1 ≤ left_i, right_i ≤ n - 1.

Гарантируется, что вход задаёт корректное двоичное дерево: в частности, если left_i ≠ -1 и right_i ≠ -1, то left_i ≠ right_i; никакая вершина не является сыном двух вершин; каждая вершина является потомком корня.

## Формат вывода

Выведите CORRECT, если дерево является корректным деревом поиска, и INCORRECT иначе.

## Пример

Ввод:
```
3
2 1 2
1 -1 -1
3 -1 -1
```
Вывод:
```
CORRECT
```
 */