```c++
#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int PartitionLomuto(int* arr, int left, int right) {
  int pivot = arr[right];
  int i = (left - 1);

  for (int j = left; j < right; j++) {
    if (arr[j] < pivot) {
      i++;
      Swap(arr[i], arr[j]);
    }
  }

  Swap(arr[i + 1], arr[right]);
  return i + 1;
}

void QuickSortLomuto(int* arr, int left, int right) {
  if (left < right) {
    int pivotIndex = PartitionLomuto(arr, left, right);
    QuickSortLomuto(arr, left, pivotIndex - 1);
    QuickSortLomuto(arr, pivotIndex + 1, right);
  }
}

int PartitionHoar(int* arr, int left, int right) {
  int pivot = arr[(left + right) / 2];
  while (left < right) {
    while (arr[left] < pivot) {
      left++;
    }
    while (arr[right] > pivot) {
      right--;
    }
    if (left <= right) {
      Swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
  return left;
}

void QuickSortHoar(int* arr, int left, int right) {
  if (left < right) {
    int pivotIndex = PartitionHoar(arr, left, right);
    QuickSortHoar(arr, left, pivotIndex - 1);
    QuickSortHoar(arr, pivotIndex + 1, right);
  }
}
int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSortHoar(arr, 0, n - 1);

  std::cout << "Sorted array:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  delete[] arr;
  return 0;
}
```