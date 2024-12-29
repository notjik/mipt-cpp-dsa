/*
# A. N-е число Фибоначчи

**Ограничение времени:** 1 секунда
**Ограничение памяти:** 256Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

Последовательностью Фибоначчи называется последовательность чисел a0, a1,…, an, …, где a0 = 0, a1 = 1, ak = ak-1 + ak-2 (k > 1).

Требуется найти N-ое число Фибоначчи.

## Формат ввода

На вход программы поступает целое число 0 ≤ N ≤ 30.

## Формат вывода

Требуется вывести N-е число Фибоначчи.

## Пример

**Ввод**

```
3
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
  int* fib = new int[n + 2];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < n + 2; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  std::cout << fib[n];
  delete[] fib;
}