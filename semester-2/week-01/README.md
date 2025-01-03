# Первая неделя. Хэш-таблицы.

### Задачи

<details><summary> 
<strong>A. Телефонная книга</strong>
</summary>

## A. Телефонная книга
**Ограничение времени:** 1 секунда
**Ограничение памяти:** 256Mb
**Ввод:** стандартный ввод или `input.txt`
**Вывод:** стандартный вывод или `output.txt`

Цель в данной задаче — реализовать простую телефонную книгу, поддерживающую три следующих типа запросов. С указанными ограничениями данная задача может быть решена с использованием таблицы с прямой адресацией.

- **add number name**: добавить запись с именем `name` и телефонным номером `number`. Если запись с таким телефонным номером уже есть, нужно заменить в ней имя на `name`.
- **del number**: удалить запись с соответствующим телефонным номером. Если такой записи нет, ничего не делать.
- **find number**: найти имя записи с телефонным номером `number`. Если запись с таким номером есть, вывести имя. В противном случае вывести `not found` (без кавычек).

Другими словами, необходимо реализовать структуру данных, эффективно обрабатывающую запросы вида `add number name`, `del number` и `find number`.

### Формат ввода

Первая строка содержит число запросов `n` (1 ≤ n ≤ 10^5). Каждая из следующих `n` строк задаёт запрос в одном из трёх описанных выше форматов.

Телефонные номера содержат не более семи цифр и не содержат ведущих нулей. Имена содержат только буквы латинского алфавита, не являются пустыми строками и имеют длину не больше 15.

Гарантируется, что среди имён не встречается строка `not found`.

### Формат вывода

Для каждого запроса `find` выведите в отдельной строке либо имя, либо `not found`.

### Пример 1

**Ввод**
```
12
add 911 police
add 76213 Mom
add 17239 Bob
find 76213
find 910
find 911
del 910
del 911
find 911
find 76213
add 76213 daddy
find 76213
```

**Вывод**
```
Mom
not found
police
not found
Mom
daddy
```

### Пример 2

**Ввод**
```
8
find 3839442
add 123456 me
add 0 granny
find 0
find 123456
del 0
del 0
find 0
```

**Вывод**
```
not found
granny
me
not found
```

###### *Решение: [\*тык\*](a.cpp)*

</details>

<details><summary> 
<strong>B. Хеширование цепочками</strong>
</summary>

## B. Хеширование цепочками

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 256Mb
**Ввод:** стандартный ввод или `input.txt`
**Вывод:** стандартный вывод или `output.txt`

Хеширование цепочками — один из наиболее популярных методов реализации хеш-таблиц на практике. Ваша цель в данной задаче — реализовать такую схему, используя таблицу с `m` ячейками и полиномиальной хеш-функцией на строках:

\[ h(S) = \left( \sum_{i=0}^{|S|-1} S[i] \cdot x^i \mod p \right) \mod m \]

где:
- \( S[i] \) — ASCII-код \(i\)-го символа строки \( S \),
- \( p = 1000000007 \) — простое число,
- \( x = 263 \).

Ваша программа должна поддерживать следующие типы запросов:
- `add string`: добавить строку `string` в таблицу. Если такая строка уже есть, проигнорировать запрос;
- `del string`: удалить строку `string` из таблицы. Если такой строки нет, проигнорировать запрос;
- `find string`: вывести `yes` или `no` в зависимости от того, есть в таблице строка `string` или нет;
- `check i`: вывести \(i\)-й список (используя пробел в качестве разделителя); если \(i\)-й список пуст, вывести пустую строку.

При добавлении строки в цепочку, строка должна добавляться в начало цепочки.

### Формат ввода

Первая строка — размер хеш-таблицы \( m \). Следующая строка содержит количество запросов \( n \). Каждая из последующих \( n \) строк содержит запрос одного из перечисленных выше четырёх типов (1 ≤ \( n \) ≤ \( 10^5 \); \( n \) ≤ \( m \) ≤ \( 10^5 \)).

Все строки имеют длину от одного до пятнадцати и содержат только буквы латинского алфавита.

### Формат вывода

Для каждого из запросов типа `find` и `check` выведите результат в отдельной строке.

### Пример 1

**Ввод**
```
5
12
add world
add HellO
check 4
find World
find world
del world
check 4
del HellO
add luck
add GooD
check 2
del good
```

**Вывод**
```
HellO world
no
yes
HellO
GooD luck
```

### Пример 2

**Ввод**
```
4
8
add test
add test
find test
del test
find test
find Test
add Test
find Test
```

**Вывод**
```
yes
no
no
yes
```

### Пример 3

**Ввод**
```
3
12
check 0
find help
add help
add del
add add
find add
find del
del del
find del
check 0
check 1
check 2
```

**Вывод**
```
no
yes
yes
no

help
```

### Примечания

**Комментарий к примеру 1:**
ASCII коды букв `w`, `o`, `r`, `l`, `d` равны 119, 111, 114, 108, 100, соответственно. Поэтому:
\[ h(world) = \left(119 + 111 \cdot 263 + 114 \cdot 263^2 + 108 \cdot 263^3 + 100 \cdot 263^4 \mod 1000000007\right) \mod 5 = 4 \]
Оказывается, что \( h(HellO) \) тоже равно четырём. Поскольку новые строки добавляются в начало списка, после второго запроса `add` список содержит строки `HellO` и `world` (именно в таком порядке). Строка `World` не находится, а `world` находится. После удаления строки `world` в цепочке 4 остаётся только строка `HellO`.

**Комментарий к примеру 3:**
Обратите внимание на то, что нужно выводить пустую строку в случае, если соответствующая цепочка пуста. Строки в запросах могут совпадать с названиями запросов.

### Подсказки по реализации:

1. Будьте осторожны с переполнением целого типа. Используйте `long long` в C++ и `long` в Java при необходимости. При вычислении значения многочлена по модулю \( p \) берите результат по модулю \( p \) после каждой арифметической операции.
2. Будьте осторожны с отрицательными числами по модулю \( p \). Во многих языках программирования \((-2) \% 5 \neq 3 \% 5\). Один из способов избежать этого — использовать \( x \leftarrow ((a \% p) + p) \% p \) вместо \( x \leftarrow a \% p \).

###### *Решение: [\*тык\*](b.cpp)*

</details>

<details>
<summary> 
<strong>C. Хеш-таблица - открытая адресация</strong>
</summary>

## C. Хеш-таблица - открытая адресация

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 64.0 Мб
**Ввод:** стандартный ввод или `input.txt`
**Вывод:** стандартный вывод или `output.txt`

Реализуйте хеш-таблицу с открытой адресацией (метод разрешения коллизий двумя указателями).

### Формат ввода

В первой строке вводится число \( N \) — количество запросов.

Далее следуют \( N \) запросов одного из видов:
- `push <строка>`
- `pop <строка>`
- `search <строка>`

### Формат вывода

После ввода команды `search` необходимо вывести `TRUE`, если искомый элемент присутствует, и `FALSE` иначе.

После ввода команды `pop` необходимо вывести `TRUE`, если требуемый элемент удалили, и `FALSE` иначе.

### Пример

**Ввод**
```
40
push ldnsxtg
push smbayt
push liur
push jjn
push vhxllwvcx
search vhxllwvcx
push xc
search smbayt
search c
search oxjhiefu
pop msxobhcg
search liur
push ws
pop srufjcp
pop ldnsxtg
pop wbiekpxj
push xk
pop uyq
search ws
search liur
pop uvstt
push j
pop liur
push wvf
pop xk
push uylo
search xc
push wmgs
pop xsgcwxgi
pop vhxllwvcx
pop nl
push mk
pop wmgs
push pvrofxc
search wxcm
pop djmrq
search cweelsqq
pop brfeokot
search jjn
push ldbfj
```

**Вывод**
```
TRUE
TRUE
FALSE
FALSE
FALSE
TRUE
FALSE
TRUE
FALSE
FALSE
TRUE
TRUE
FALSE
TRUE
TRUE
TRUE
FALSE
TRUE
FALSE
TRUE
FALSE
FALSE
FALSE
FALSE
TRUE
```

### Примечания

Для реализации хеш-таблицы с открытой адресацией можно использовать различные методы, такие как линейное пробирование, квадратичное пробирование или двойное хеширование. В данной задаче рекомендуется использовать двойное хеширование для разрешения коллизий.

Примерный алгоритм:
1. Вычислить основное и дополнительное хеш-значения для строки.
2. Для каждой операции (`push`, `pop`, `search`) использовать эти хеш-значения для определения позиции в таблице, проверяя и/или изменяя ячейки по определённому правилу.

Обратите внимание, что строки в запросах могут содержать до 15 символов и включают только буквы латинского алфавита.

###### *Решение: [\*тык\*](c.cpp)*

</details>

###### *Конспект лекции: [\*тык\*](aads-lecture-1.pdf)*
###### *Запись лекции: [\*тык\*](https://youtu.be/9lZ-WFbJl9M)*