/*
# Задача E(3). Скобки [АиСД-23]

**Ограничение времени**: 1 секунда
**Ограничение памяти**: 256.0 Мб
**Ввод**: стандартный ввод или input.txt
**Вывод**: стандартный вывод или output.txt

## Маша и расставленные скобки. Нет, так дело не пойдёт… Щас мы всё тут украсим!

Как всем известно, Маша - девочка не очень взрослая, хотя и самостоятельная. Конечно, в ВУЗ ей еще не скоро поступать... но математику и программирование то надо знать!

Так вот Маша и пошла к Мишке учиться программированию - а именно так, как расставляются скобочки в языке программирования PyFilm.

Известно, что в этом языке программирования можно использовать 3 вида скобочек: {},[],()

Причем некоторые, а именно {,(,[, называются открывающими, а некоторые, соответствующие первым, },),] называются закрывающими.

Необходимо понять, правильно ли расставлены скобки в введенной строчке: а именно каждой открывающей найдется закрывающая. В случае, если скобки расставлены неверно, программа должна показывать Маше, где (в каком символе) допущена ошибка.

## Формат ввода

Строка, длины не более 10^5, состоящая из заглавных и прописных букв латинского алфавита, чисел, скобок []{}() и знаков препинания.

## Формат вывода

Либо строку Success, если последовательность скобок корректна, либо индекс (индексация с единицы) первой закрывающей скобки, для которой нет своей открывающей. Если такой скобки нет, выведите индекс первой открывающей скобки, для которой нет своей закрывающей.

## Примеры

### Пример 1
#### Ввод
```
([](){([])})
```
#### Вывод
```
Success
```
### Пример 2
#### Ввод
```
()[]}
```
#### Вывод
```
5
```
### Пример 3
#### Ввод
```
{{[()]}
```
#### Вывод
```
1
```
### Пример 4
#### Ввод
```
print)hello(world
```
#### Вывод
```
6
```
### Пример 5
#### Ввод
```
print(hello)world
```
#### Вывод
```
Success
```

**Примечания**: Маша изучила std::string и std::stack, ими теперь можно пользоваться!
 */
#include <cstdint>
#include <climits>
#include <iostream>

int Min(int a, int b) {
  return (a <= b ? a : b);
}

struct Pair {
  bool status = false;
  int64_t count = 0;
  int64_t index_first = -1;
};

int main() {
  char input[static_cast<int>(10e5)];
  std::cin >> input;
  int i = 0;
  // () - 1 // [] - 2 // {} - 3 //
  Pair type1;
  Pair type2;
  Pair type3;
  int last_open = -1;
  while (input[i] != '\0') {
    // open
    if (input[i] == '(') {
      type1.count++;
      if (!type1.status) {
        type1.status = true;
        type1.index_first = i;
      }
      last_open = 1;
    }
    if (input[i] == '[') {
      type2.count++;
      if (!type2.status) {
        type2.status = true;
        type2.index_first = i;
      }
      last_open = 2;
    }
    if (input[i] == '{') {
      type3.count++;
      if (!type3.status) {
        type3.status = true;
        type3.index_first = i;
      }
      last_open = 3;
    }
    // close
    if (input[i] == ')') {
      if (!type1.status || last_open != 1) {
        std::cout << i + 1;
        return 0;
      } else if (type1.count == 1) {
        type1.status = false;
        type1.count--;
        type1.index_first = -1;
      } else {
        type1.count--;
      }
    }
    if (input[i] == ']' || last_open != 2) {
      if (!type2.status) {
        std::cout << i + 1;
        return 0;
      } else if (type2.count == 1) {
        type2.status = false;
        type2.count--;
        type2.index_first = -1;
      } else {
        type2.count--;
      }
    }
    if (input[i] == '}' || last_open != 3) {
      if (!type3.status) {
        std::cout << i + 1;
        return 0;
      } else if (type3.count == 1) {
        type3.status = false;
        type3.count--;
        type3.index_first = -1;
      } else {
        type3.count--;
      }
    }
    i++;
  }
  int res = INT_MAX;
  if (type1.status) {
    res = Min(res, type1.index_first + 1);
  }
  if (type2.status) {
    res = Min(res, type2.index_first + 1);
  }
  if (type3.status) {
    res = Min(res, type3.index_first + 1);
  }
  if (res == INT_MAX) {
    std::cout << "Success";
  } else {
    std::cout << res;
  }
  return 0;
}