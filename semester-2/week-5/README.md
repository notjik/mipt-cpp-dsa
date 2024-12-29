# Пятая неделя. Графы. BFS. 1-k BFS. Алгоритм Дейкстры.

## Задачи

<details><summary> 
<strong>A. Кратчайший путь</strong>
</summary>

### A. Кратчайший путь

Ограничение времени: 1 секунда  
Ограничение памяти: 128Mb

**Формат ввода**  
В первой строке входного файла идут целые числа \( n \) и \( m \) (1 ≤ \( n \) ≤ 50 000, 1 ≤ \( m \) ≤ 100 000) — количество вершин и рёбер соответственно. Во второй строке идут целые числа \( a \) и \( b \) — стартовая и конечная вершины соответственно. Далее идут \( m \) строк, описывающих рёбра.

**Формат вывода**  
Если пути между \( a \) и \( b \) нет, выведите единственное число -1. Иначе выведите в первой строке число \( l \) — длину кратчайшего пути между этими двумя вершинами в рёбрах, а во второй строке выведите \( l + 1 \) число — вершины этого пути.

**Пример 1**

Ввод:
```
4 5
1 4
1 3
3 2
2 4
2 1
2 3
```

Вывод:
```
2
1 2 4
```

**Пример 2**

Ввод:
```
4 4
2 3
2 1
2 4
4 3
1 3
```

Вывод:
```
2
2 1 3
```

###### *Решение: [\*тык\*](a.cpp)*

</details>

<details><summary> 
<strong>B. Найти минимальный путь</strong>
</summary>

### B. Найти минимальный путь

Ограничение времени: 0.2 секунды  
Ограничение памяти: 32Mb

**Формат ввода**  
В первой строке входного файла два числа: \( N \) и \( M \) (1 ≤ \( N \) ≤ 100, 0 ≤ \( M \) ≤ 10000), где \( N \) — количество вершин графа, а \( M \) — количество ребер.

В следующей строке заданы числа \( S \) и \( F \) — начальная и конечная вершины.

Далее следует \( M \) троек чисел \( A_i \), \( B_i \), \( T_i \) (1 ≤ \( T_i \) ≤ 10) — номера вершин соединенных ребром и вес данного ребра.

**Формат вывода**  
Вывести искомое расстояние или -1, если пути между указанными вершинами не существует.

**Пример**

Ввод:
```
3 6
2 1
1 2 1
1 3 1
2 1 4
2 3 1
3 1 2
3 2 1
```

Вывод:
```
3
```

###### *Решение: [\*тык\*](b.cpp)*

</details>

<details><summary> 
<strong>C. Автобусные маршруты</strong>
</summary>

### C. Дейкстра

Ограничение времени: 2 секунды  
Ограничение памяти: 256Mb

Дан ориентированный взвешенный граф (V, E). Найдите кратчайшее расстояние от одной заданной вершины до другой. Асимптотика O(V² + E).

**Формат ввода**  
В первой строке входного файла три числа: \( N \), \( S \) и \( F \) (1 ≤ \( N \) ≤ 2000, 1 ≤ \( S \), \( F \) ≤ \( N \)), где \( N \) — количество вершин графа, \( S \) — начальная вершина, а \( F \) — конечная.  
В следующих \( N \) строках по \( N \) чисел — матрица смежности графа, где -1 означает отсутствие ребра между вершинами, а любое целое неотрицательное число — присутствие ребра данного веса. На главной диагонали матрицы всегда нули.

**Формат вывода**  
Вывести искомое расстояние или -1, если пути не существует.

**Пример**

Ввод:
```
3 1 2
0 -1 2
3 0 -1
-1 4 0
```

Вывод:
```
6
```

###### *Решение: [\*тык\*](c.cpp)*

</details>

###### *Конспект лекции: [\*тык\*](aads-lecture-5.pdf)*
###### *Запись лекции: [\*тык\*](https://youtu.be/rZUqpEz0r1A)*