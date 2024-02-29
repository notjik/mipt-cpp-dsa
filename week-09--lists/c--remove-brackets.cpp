/*
# C. Удалите скобки

**Ограничение времени:** 0.5 секунды
**Ограничение памяти:** 64Mb
**Ввод:** стандартный ввод или input.txt
**Вывод:** стандартный вывод или output.txt

## Задача

Дана строка, составленная из круглых скобок. Определите, какое наименьшее количество символов необходимо удалить из этой строки, чтобы оставшиеся символы образовывали правильную скобочную последовательность.

## Формат ввода

Во входном файле записана строка из круглых скобок. Длина строки не превосходит 100000 символов.

## Формат вывода

Выведите единственное целое число — ответ на поставленную задачу.
 */
#include <iostream>

int main() {
  char str[100001];
  std::cin >> str;
  int del = 0;
  int open = 0;
  {
    int cur = 0;
    while (str[cur] != '\0') {
      if (str[cur] == '(') {
        open++;
      } else if (str[cur] == ')') {
        if (open > 0) {
          open--;
        } else {
          del++;
        }
      }
      cur++;
    }
  }
  std::cout << del + open;
  return 0;
}