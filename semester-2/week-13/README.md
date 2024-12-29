# Тринадцатая неделя. Строки. Префикс-функция. Z-функция. Бор.

<details><summary> 
<strong>A. Префикс-функция</strong>
</summary>

### A. Префикс-функция

**Ограничение времени**: 1 секунда  
**Ограничение памяти**: 16Mb

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

"Не хочешь отправиться в путешествие, Ишак?"

Дана непустая строка S, длина которой N не превышает \(10^6\). Будем считать, что элементы строки нумеруются от 0 до \(N-1\).

Для каждой позиции i символа в строке нас будет интересовать подстрока, заканчивающаяся в этой позиции, и совпадающая с некоторым началом всей строки.

Вообще говоря, таких подстрок будет несколько, не меньше двух. Самая длинная из них имеет длину \(i + 1\), она нас интересовать не будет. А будет нас интересовать самая длинная из остальных таких подстрок (заметим, что такая подстрока всегда существует — в крайнем случае, если ничего больше не найдется, сгодится пустая подстрока).

Значением префикс-функции будем считать длину этой подстроки. Префикс-функция используется в различных алгоритмах обработки строк. В частности, с её помощью можно быстро решать задачу о поиске вхождения одной строки в другую («поиск образца в тексте»).

Требуется для всех i от 0 до \(N-1\) вычислить префикс-функцию.

**Формат ввода**  
Одна строка длины N, (1 ≤ N ≤ \(10^6\)), состоящая из строчных латинских букв.

**Формат вывода**  
Выведите N чисел — значения префикс-функции для каждой позиции, разделенные пробелом.

**Пример**

Ввод:
```
abracadabra
```

Вывод:
```
0 0 0 1 0 1 0 1 2 3 4
```

###### *Решение: [\*тык\*](a.cpp)*

</details>

<details><summary> 
<strong>B. Z-функция</strong>
</summary>

### B. Z-функция

**Ограничение времени**: 1 секунда  
**Ограничение памяти**: 16.0 Мб

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

"Шрек, все не так плохо, просто на улице дождь и мрак, и папаша Фионы нанял гада, чтобы тебя убить."

Дана непустая строка S, длина которой N не превышает 10^6. Будем считать, что элементы строки нумеруются с 0 до N-1.

Для каждой позиции i символа в строке определим Z-блок как наибольшую подстроку, которая начинается в этой позиции и совпадает с некоторым началом всей строки S. Значением Z-функции Z[i] будем считать длину этого Z-блока.

Z-функция используется в различных алгоритмах обработки строк. В частности, с её помощью можно быстро решать задачу о поиске вхождения одной строки в другую ("поиск образца в тексте").

Требуется для всех i от 0 до N-1 вычислить Z[i].

**Формат ввода**  
Одна строка длины N (1 ≤ N ≤ 10^6), состоящая из строчных латинских букв.

**Формат вывода**  
N чисел, разделенные пробелами: Z[0], Z[1], ..., Z[N-1].

**Пример**

Ввод:
```
abracadabra
```

Вывод:
```
11 0 0 1 0 1 0 4 0 0 1
```

###### *Решение: [\*тык\*](b.cpp)*

</details>

<details><summary> 
<strong>C. КМП</strong>
</summary>

### C. КМП

**Ограничение времени**: 0.1 секунд  
**Ограничение памяти**: 16.0 Мб

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

"Шрек, помнишь, как ты говорил, что великаны многослойные? Должен тебе признаться в том, что ослы устроены проще. Наши страхи написаны у нас на лбу."

Шрек так запутался в слоях, что стал бояться своих чувств. Неизвестно, как в Средневековье, но в современном мире все подобные ситуации решаются просто — походом к психотерапевту. Тот попросил Шрека выписать все слова, что приходят на ум и теперь анализирует чувства великана, смотря как часто в тексте появляются слова-триггеры. Работа муторная, кропотливая, а потому стоит того, чтобы переложить её на кого-то другого. Теперь доктор просит вас помочь найти все вхождения строки P в строку S.

**Формат ввода**  
Первые две строки входных данных содержат строки S и P, соответственно. Длины строк больше 0 и меньше 5⋅10^4, строки содержат только латинские буквы.

**Формат вывода**  
Выведите номера символов, начиная с которых строка P входит в строку S, в порядке возрастания.

**Пример**

Ввод:
```
ababbababa
aba
```

Вывод:
```
0
5
7
```

###### *Решение: [\*тык\*](c.cpp)*

</details>

<details><summary> 
<strong>D. Компаратор</strong>
</summary>

### D. Компаратор

**Ограничение времени**: 1 секунда  
**Ограничение памяти**: 16Mb

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

Юный программист Саша написал свою первую тестирующую систему. Он так обрадовался тому, что она скомпилировалась, что решил пригласить школьных друзей на свой собственный контест.

Но в конце тура выяснилось, что система не умеет сортировать команды в таблице результатов. Помогите Саше реализовать эту сортировку.

Команды упорядочиваются по правилам ACM:
- по количеству решённых задач в порядке убывания;
- при равенстве количества решённых задач – по штрафному времени в порядке возрастания;
- при прочих равных — по номеру команды в порядке возрастания.

Используйте в этой задаче STL, algorithm и функторы.

**Формат ввода**  
Первая строка содержит натуральное число n (1 ≤ n ≤ 105) — количество команд, участвующих в контесте.

В i-й из следующих n строк записано количество решенных задач S (0 ≤ S ≤ 100) и штрафное время T (0 ≤ T ≤ 105) команды с номером i.

**Формат вывода**  
В выходной файл выведите n чисел — номера команд в отсортированном порядке.

**Пример**

Ввод:
```
5
3 50
5 720
1 7
0 0
8 500
```

Вывод:
```
5
2
1
3
4
```

**Примечание**
В примере, команда с номером 5 решает 8 задач и получает штрафное время 500. Эта команда занимает первое место. Команда с номером 2 решает 5 задач и получает штрафное время 720, занимая второе место и так далее.

</details>

<details><summary> 
<strong>E. Зверюшки</strong>
</summary>

### E. Зверюшки

**Ограничение времени**: 0.6 секунд  
**Ограничение памяти**: 32Mb

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

Уже долгое время в Институте Фич, Компьютеров и Новшеств разводят милых разноцветных зверюшек. Для удобства каждый цвет обозначен своим номером, всего цветов не более 10^9.

В один из прекрасных дней в питомнике случилось чудо: все зверюшки выстроились в ряд в порядке возрастания цветов. Пользуясь случаем, лаборанты решили посчитать, сколько зверюшек разных цветов живет в питомнике, и, по закону жанра, попросили вас написать программу, которая поможет им в решении этой нелегкой задачи.

Для решения этой задачи используйте STL и библиотеку algorithm.

**Формат ввода**  
В первой строке входного файла содержится единственное число N (0 ≤ N ≤ 10^5) — количество зверюшек в Институте.

В следующей строке находятся N упорядоченных по неубыванию неотрицательных целых чисел, не превосходящих 10^9 и разделенных пробелами — их цвета.

В третьей строке файла записано число M (1 ≤ M ≤ 100000) — количество запросов вашей программе, в следующей строке через пробел записаны M целых неотрицательных чисел (не превышающих 10^9 + 1).

**Формат вывода**  
Выходной файл должен содержать M строчек. Для каждого запроса выведите число зверюшек заданного цвета в питомнике.

**Пример**

Ввод:
```
10
1 1 3 3 5 7 9 18 18 57
5
57 3 9 1 179
```

Вывод:
```
1
2
1
2
0
```

</details>

<details><summary> 
<strong>F. Встреча</strong>
</summary>

### F. Встреча

**Ограничение времени**: 0.5 секунд  
**Ограничение памяти**: 16Mb

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

Напишите программу, которая определяет, сколько раз встречается заданное число x в данном массиве. Используйте последовательный контейнер и библиотеку алгоритмов для решения задачи. Старайтесь избегать циклов.

**Формат ввода**  
В первой строке задается одно натуральное число N, не превосходящее 1,000,000 — размер массива.

Во второй строке вводятся N чисел — элементы массива (целые числа, не превосходящие по модулю 1,000).

В третьей строке содержится одно целое число x, не превосходящее по модулю 1,000,000.

**Формат вывода**  
Вывести одно число — сколько раз встречается x в данном массиве.

**Пример**

Ввод:
```
5
1 2 3 4 5
3
```

Вывод:
```
1
```

</details>

<details><summary> 
<strong>G. Словарь</strong>
</summary>

### G. Словарь

**Ограничение времени**: 1 секунда  
**Ограничение памяти**: 256Mb

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

Вам дан словарь, состоящий из пар слов. Каждое слово является синонимом к парному ему слову. Все слова в словаре различны. Для каждого данного слова определите его синоним.

Для решения данной задачи используйте STL.

**Формат ввода**  
Программа получает на вход количество пар синонимов N (0 ≤ N ≤ 10^5). Далее следует N строк, каждая строка содержит ровно два слова-синонима.

Затем идет число Q (1 ≤ Q ≤ 10^5) — количество запросов к словарю. Далее на каждой следующей из Q строк идет слово, к которому надо вывести синоним.

**Формат вывода**  
Программа должна вывести синонимы к данным слову на отдельных строках.

**Пример**

Ввод:
```
3
car plane
mouse cat
base stream
3
plane
stream
base
```

Вывод:
```
car
base
stream
```

</details>

<details><summary> 
<strong>H. Банк</strong>
</summary>

### H. Банк

**Ограничение времени**: 0.5 секунд  
**Ограничение памяти**: 8Mb

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

У банка есть клиенты. Каждый клиент имеет ровно один счет.

Напишите программу, которая будет выполнять последовательность запросов таких двух видов:

1. Начинается с числа 1, затем через пробел следует имя клиента (слово из латинских букв), далее через пробел идет сумма денег, которую клиент кладет или берет из счета в банке (целое число, не превышает по модулю 10000).
2. Начинается с числа 2, через пробел следует имя клиента. На каждый такой запрос программа должна ответить, какая сумма в данный момент есть на счету заданного клиента. Если такое имя клиента пока ни разу не упоминалось в запросах вида 1, выводите вместо числа слово «ERROR».

В начале работы программы у всех клиентов на счету 0. Затем суммы могут становиться как положительными, так и отрицательными.

Обратите внимание, что в ситуации, когда клиент снял суммарно ровно столько же денег, сколько положил, сумма на счете становится равной 0, но, раз его имя уже встречалось, нулевое значение не является основанием выводить «ERROR».

Для решения задачи используйте ассоциативный контейнер.

**Формат ввода**  
Первая строка стандартного входного потока содержит количество запросов N (1 ≤ N ≤ 10^5). Далее следуют N строк, в каждой из которых описан один из двух видов запроса.

**Формат вывода**  
На каждый запрос 2-го вида нужно вывести текущее значение на счету заданного клиента (или слово «ERROR»).

**Пример**

Ввод:
```
7
1 asdf 3
1 zxcv 5
2 asdf
1 asdf -2
2 asdf
2 lalala
2 zxcv
```

Вывод:
```
3
1
ERROR
5
```

###### *Решение: [\*тык\*](h.cpp)*

</details>

<details><summary> 
<strong>I. Частотность</strong>
</summary>

### I. Частотность

**Ограничение времени**: 1 секунда  
**Ограничение памяти**: 64Mb

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

Дан текст. Выведите все слова, встречающиеся в тексте, по одному на каждую строку. Слова должны быть отсортированы по убыванию их количества появления в тексте, а при одинаковой частоте появления в лексикографическом порядке.

**Формат ввода**  
Вводится текст — последовательность строк через пробел или перенос строки.

**Формат вывода**  
Выведите ответ на задачу.

**Пример**

Ввод:
```
hi
hi
what is your name
my name is bond
james bond
my name is damme
van damme
claude van damme
jean claude van damme
```

Вывод:
```
damme
is
name
van
bond
claude
hi
my
james
jean
what
your
```

</details>

<details><summary> 
<strong>J. База данных</strong>
</summary>

### J. База данных

**Ограничение времени**: 1 секунда  
**Ограничение памяти**: 64Mb

**Ввод**: стандартный ввод или input.txt  
**Вывод**: стандартный вывод или output.txt

Дана база данных о продажах некоторого интернет-магазина. Каждая строка входного файла представляет собой запись вида покупатель-товар-количество, где покупатель — имя покупателя (строка без пробелов), товар — название товара (строка без пробелов), количество — количество приобретённых единиц товара.

Создайте список всех покупателей и для каждого покупателя подсчитайте количество приобретенных им единиц каждого вида товаров.

**Формат ввода**  
Во входном файле записано не более 10^5 строк в указанном формате.

Имена покупателей и названия товаров представляют собой строки из заглавных и строчных латинских букв не длиннее 10 символов. Количество товара в каждой покупке — натуральное число, не превышающее 10^6.

**Формат вывода**  
Выведите список всех покупателей в лексикографическом порядке, после имени каждого покупателя выведите двоеточие, затем выведите список названий всех приобретенных данным покупателем товаров в лексикографическом порядке, после названия каждого товара выведите количество единиц товара, приобретенных данным покупателем.

Информация о каждом товаре выводится в отдельной строке.

**Пример**

Ввод:
```
Ivanov paper 10
Petrov pen 5
Ivanov marker 3
Ivanov paper 7
Petrov envelope 20
Ivanov envelope 5
```

Вывод:
```
Ivanov:
envelope 5
marker 3
paper 17
Petrov:
envelope 20
pen 5
```

</details>


###### *Конспект лекции: [\*тык\*](aads-lecture-13.pdf)*
###### *Запись лекции: [\*тык\*](https://youtu.be/Oo-uGyeVKMw)*