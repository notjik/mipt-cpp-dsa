/*
# Задача A. Гарри Поттер и НОП

**Ограничение времени**: 0.5 секунд
**Ограничение памяти**: 64.8 Мб
**Ввод**: стандартный ввод или input.txt
**Вывод**: стандартный вывод или output.txt

Трагедия детства столкнула Полумну Лавгуд с тем, что она видит фестралов. Это внушило ей веру в то, что существ намного больше, чем мы можем увидеть и даже почувствовать.

Хоть большинство из них она и выдумала.

Даны две последовательности, требуется найти и вывести их наибольшую общую подпоследовательность.

## Формат ввода

В первой строке входных данных содержится число N - длина первой последовательности (1 ≤ N ≤ 1000). Во второй строке заданы члены первой последовательности (через пробел) - целые числа, не превосходящие 10000 по модулю.

В третьей строке записано число M - длина второй последовательности (1 ≤ M ≤ 1000). В четвертой строке задаются члены второй последовательности (через пробел) - целые числа, не превосходящие 10000 по модулю.

## Формат вывода

Требуется вывести наибольшую общую подпоследовательность данных последовательностей, через пробел.

## Пример

### Ввод
```
3
1 2 3
4
2 3 1 5
```
### Вывод
```
2 3
```
 */
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  auto first = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> first[i];
  }
  int m;
  std::cin >> m;
  auto second = new int[m];
  for (int i = 0; i < m; i++) {
    std::cin >> second[i];
  }
  auto dp = new int* [n + 1];
  for (int i = 0; i < n + 1; i++) {
    dp[i] = new int[m + 1]{};
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (first[i - 1] == second[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  auto res = new int[dp[n][m]];
  {
    int i = n;
    int j = m;
    while (dp[i][j]) {
      if (dp[i][j] == dp[i - 1][j]) {
        i--;
      } else if (dp[i][j] == dp[i][j - 1]) {
        j--;
      } else {
        res[dp[i][j] - 1] = first[i - 1];
        i--;
        j--;
      }
    }
  }
  for (int i = 0; i < dp[n][m]; i++) {
    std::cout << res[i] << " ";
  }
  delete[] first;
  delete[] second;
  for (int i = 0; i < n + 1; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  delete[] res;
  return 0;
}
