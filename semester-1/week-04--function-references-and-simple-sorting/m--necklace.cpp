/*
 * M. Ожерелье
Ограничение времени	1 секунда
Ограничение памяти	256Mb
Ввод	стандартный ввод или input.txt
Вывод	стандартный вывод или output.txt
В витрине ювелирного магазина стоит манекен, на шею которого надето ожерелье. Оно состоит из n колечек, нанизанных на замкнутую нить. Все колечки имеют разные размеры. В зависимости от размера колечки пронумерованы числами от 1 до n, начиная с самого маленького и до самого большого. Колечки можно передвигать вдоль нити и протаскивать одно через другое, но только в том случае, если номера этих колечек отличаются более чем на единицу.
Продавец хочет упорядочить колечки так, чтобы они располагались по возрастанию номеров вдоль нити по часовой стрелке. Снимать ожерелье с манекена нельзя.
Требуется написать программу, которая по заданному начальному расположению колечек находит последовательность протаскиваний колечек одно через другое, приводящую исходное расположение колечек в желаемое.

Формат ввода
Первая строка входных данных содержит число n (2≤N≤50).
Во второй строке через пробел следуют n различных чисел от 1 до n — номера колечек, расположенных вдоль нити по часовой стрелке.

Формат вывода
Ваша программа должна вывести описание процесса упорядочения.
В каждой строке выходных данных, кроме последней, должны быть записаны через пробел два числа, указывающие номера колечек, протаскиваемых друг через друга. В последней строке должен стоять ноль.
Количество выводимых строк не должно превышать 50000.
Если требуемого упорядочения колечек достичь не удается, программа должна вывести одно число -1.
 */
#include <iostream>

int **res = new int *[50000];
int idx_res = 0;

void Move(int *arr, const int size, int to) {
  int *new_arr = new int[size];
  for (int i = 0; i < size; i++) {
    new_arr[i] = arr[(i + to) % size];
  }
  for (int i = 0; i < size; i++) {
    arr[i] = new_arr[i];
  }
  delete[] new_arr;
}

bool IsSorted(const int *arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] >= arr[i + 1]) {
      return false;
    }
  }
  return true;
}

void Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void BubbleSort(int *arr, const int size) {
  for (int i = 0; i < size; i++) {
    bool is_permutations = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[j + 1] && abs(arr[j] - arr[j + 1]) > 1 && idx_res < 50000) {
        Swap(arr[j], arr[j + 1]);
        res[idx_res][0] = arr[j];
        res[idx_res][1] = arr[j + 1];
        idx_res++;
        is_permutations = true;
      }
    }
    if (!is_permutations) {
      break;
    }
  }
}

int main() {
  for (int i = 0; i < 50000; i++) {
    res[i] = new int[2];
  }

  int n;
  std::cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  while (!IsSorted(arr, n) && idx_res < 50000) {
    BubbleSort(arr, n);
    int idx_one = 0;
    while (arr[idx_one] != 1) {
      idx_one++;
    }
    Move(arr, n, idx_one);
  }
  if (idx_res < 50000 && IsSorted(arr, n)) {
    for (int i = 0; i < idx_res; i++) {
      std::cout << res[i][0] << ' ' << res[i][1] << '\n';
    }
    std::cout << 0;
  } else {
    std::cout << -1;
  }
  delete[] arr;
}