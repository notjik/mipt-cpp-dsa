/*
# B. Камни

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 256Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

На столе изначально лежат N камней. За ход игрок может взять 1 или 2 камня, если текущее число камней делится на 3; 1 или 3, если текущее число камней при делении на 3 дает остаток один; 1, 2 или 3, если текущее число камней при делении на 3 дает остаток два. Каждый ход можно сделать при наличии достаточного количества камней. Проигрывает тот, кто хода сделать не может.

## Формат ввода

Вводится целое число 0 < N ≤ 100.

## Формат вывода

Выведите 1 или 2 – номер игрока, который выиграет при правильной игре.

## Пример

**Ввод**

```
42
```

**Вывод**

```
2
```
 */
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << (n % 3 != 0 ? '1' : '2');
}