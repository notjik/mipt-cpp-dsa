#include <iostream>

int Partition(int* arr, int left, int right, bool& reverse) {
  int mid = (left + right) / 2;
  int pivot = arr[mid];
  while (left < right) {
    while (reverse ? arr[left] > pivot : arr[left] < pivot) {
      left++;
    }
    while (reverse ? arr[right] < pivot : arr[right] > pivot) {
      right--;
    }
    if (left >= right) {
      break;
    }
    std::swap(arr[left], arr[right]);
    left++;
    right--;
  }
  return right;
}

void QuickSortBackend(int* arr, int left, int right, bool& reverse) {
  if (left < right) {
    int pivot = Partition(arr, left, right, reverse);
    QuickSortBackend(arr, left, pivot, reverse);
    QuickSortBackend(arr, pivot + 1, right, reverse);
  }
}

void QuickSort(int* arr, int size, bool reverse = false) {
  QuickSortBackend(arr, 0, size - 1, reverse);
}

int main() {
  int weight, n;
  std::cin >> weight >> n;
  int* backpack = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> backpack[i];
  }
  QuickSort(backpack, n);
  int i = 0;
  int add = 0;
  while (i < n && add + backpack[i] <= weight) {
    add += backpack[i];
    i++;
  }
  std::cout << i << ' ';
  i--;
  add -= backpack[i];
  while (i < n && add + backpack[i] <= weight) {
    i++;
  }
  i--;
  std::cout << backpack[i] + add << '\n';
  delete[] backpack;
}