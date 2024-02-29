/*
 * K. Экспедиция
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
Месклиниты собрались в экспедицию на край света. У них есть корабль, состоящий из n×m плотиков, связанных между собой. У каждого плотика есть своя грузоподъемность, а у каждого месклинита – своя масса. На каждом плотике может находиться не более одного месклинита. Если грузоподъемность выбранного плотика меньше массы месклинита, то бедный месклинит утонет при посадке.
Руководитель экспедиции продумывает рассадку по плотикам. Помогите ему определить, какому максимальному количеству месклинитов удастся отправиться в путь.

Формат ввода
В первой строке даны числа n и m (1≤n,m≤40).
В каждой из последующих n строк содержится по m чисел, обозначающих грузоподъемность соответствующего плотика. В (n+2)-ой строке находится число k (1≤k≤2000) – количество месклинитов. В (n+3)-ей строке содержатся k чисел, i-ое из которых – масса i-ого месклинита. Все массы месклинитов и грузоподъемности плотиков – натуральные числа, не превышающие 10^9.

Формат вывода
Требуется вывести одно число – максимально возможное количество участников экспедиции.
 */
#include <iostream>

void InsertionSort(int *arr, const int size, bool reverse = false) {
  for (int i = 1; i < size; i++) {
    int x = arr[i];
    int j = i - 1;
    while (j >= 0 && (reverse ? arr[j] < x : arr[j] > x)) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = x;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  int *rafts = new int[n * m];
  for (int i = 0; i < n * m; i++) {
    std::cin >> rafts[i];
  }
  InsertionSort(rafts, n * m, true);
  int k;
  std::cin >> k;
  int *mesklinites = new int[k];
  for (int i = 0; i < k; i++) {
    std::cin >> mesklinites[i];
  }
  InsertionSort(mesklinites, k, true);
  int cur_raft = 0;
  int cur_mesklinites = 0;
  int res = 0;
  while (cur_raft < n * m && cur_mesklinites < k) {
    if (rafts[cur_raft] >= mesklinites[cur_mesklinites]) {
      res++;
      cur_raft++;
      cur_mesklinites++;
    } else {
      cur_mesklinites++;
    }
  }
  std::cout << res;
  delete[] rafts;
  delete[] mesklinites;
  return 0;
}