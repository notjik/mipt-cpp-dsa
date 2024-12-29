# Девятая неделя. Графы. Наибольшее паросочетание. Алгоритм Куна. Теорема Бержа.

## Задачи

<details><summary> 
<strong>A. Паросочетание</strong>
</summary>

### A. Паросочетание

**Ограничение времени**: 2 секунды  
**Ограничение памяти**: 64Mb  
**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

Двудольным графом называется неориентированный граф (V, E), такой, что его множество вершин V можно разбить на два множества A и B, для которых \(e1 ∈ A, e2 ∈ B\) и , .

Паросочетанием в двудольном графе называется любой набор его несмежных рёбер, то есть такой набор , что для любых двух рёбер \(e1 = (u1, v1), e2 = (u2, v2)\) из S и .

Ваша задача — найти максимальное паросочетание в двудольном графе, то есть паросочетание с максимально возможным числом рёбер.

### Формат ввода
В первой строке записаны два целых числа \(n\) и \(m\) (\(1 \leq n, m \leq 500\)), где \(n\) — число вершин в множестве A, а \(m\) — число вершин в B.

Далее следуют \(n\) строк с описаниями рёбер — i-я вершина из A описана в (i+1)-й строке файла. Каждая из этих строк содержит номера вершин из B, соединённых с i-й вершиной A. Гарантируется, что в графе нет кратных ребер. Вершины в A и B нумеруются независимо (с единицы). Список завершается числом 0.

### Формат вывода
Первая строка выходного файла должна содержать одно целое число \(l\) — количество рёбер в максимальном паросочетании. Далее следуют \(l\) строк, в каждой из которых должны быть два целых числа \(u_j\) и \(v_j\) — концы рёбер паросочетания в A и B соответственно.

### Пример

**Ввод**
```
2 2
1 2 0
2 0
```

**Вывод**
```
2
1 1
2 2
```

###### *Решение: [\*тык\*](a.cpp) (не доделано)*

</details>

<details><summary> 
<strong>B. Двигаем предметы</strong>
</summary>

### B. Двигаем предметы

**Ограничение времени**: 2 секунды  
**Ограничение памяти**: 512Mb  
**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

На плоскости расположены \(n\) предметов, их нужно переместить в заданные \(n\) позиций. При этом не важно, какой предмет какую из них займет. Для каждого предмета известна максимальная скорость, с которой его можно перемещать, при этом перемещать все предметы можно одновременно. Найдите минимальное время, за которое можно переместить предметы на заданные места.

### Формат ввода
В первой строке записано число \(n\) (\(1 \leq n \leq 50\)), в следующих \(n\) строках содержатся описания предметов, в \(i\)-й из которых, находится три числа координаты \(x_i, y_i\) (\(1 \leq x_i, y_i \leq 1000\)) и максимальная скорость \(v_i\) (\(1 \leq v_i \leq 10\)) \(i\)-го предмета соответственно. В следующих \(n\) строках содержатся описания финальных позиций, в \(i\)-й из которых, заданы координаты \(a_i, b_i\) (\(1 \leq a_i, b_i \leq 1000\)) \(i\)-й финальной позиции.

### Формат вывода
Выведите одно число — минимальное время, за которое можно переместить предметы. Погрешность не более \(10^{-4}\).

### Пример 1

**Ввод**:
```
2
0 0 1
0 1 1
1 1
1 0
```

**Вывод**:
```
1.0
```

### Пример 2

**Ввод**:
```
2
0 0 1
0 1 1
1 1
2 1
```

**Вывод**:
```
2.0
```

### Пример 3

**Ввод**:
```
2
0 0 1
5 0 1
5 12
10 12
```

**Вывод**:
```
13.0
```

### Пример 4

**Ввод**:
```
2
0 0 2
5 0 1
5 12
10 12
```

**Вывод**:
```
12.0
```

### Пример 5

**Ввод**:
```
4
78 520 5
827 239 5
620 200 7
809 269 7
986 496
754 745
772 375
44 223
```

**Вывод**:
```
68.45242650102003
```

</details>

###### *Конспект лекции: [\*тык\*](aads-lecture-9.pdf)*
###### *Запись лекции: [\*тык\*](https://youtu.be/Eg3-BUmAbQM)*