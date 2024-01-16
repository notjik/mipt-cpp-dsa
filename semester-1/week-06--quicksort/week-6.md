## Сортировка метолом Хоара
```c++
#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int Partition(int* arr, int left, int right) {
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

void QuickSort(int* arr, int left, int right) {
  if (left < right) {
    int pivotIndex = Partition(arr, left, right);
    QuickSort(arr, left, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, right);
  }
}
int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSort(arr, 0, n - 1);

  std::cout << "Sorted array:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  delete[] arr;
  return 0;
} 
```

## Сортировка методом Ломуто
```c++
#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int Partition(int* arr, int left, int right) {
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

void QuickSort(int* arr, int left, int right) {
  if (left < right) {
    int pivotIndex = Partition(arr, left, right);
    QuickSort(arr, left, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, right);
  }
}

int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSort(arr, 0, n - 1);

  std::cout << "Sorted array:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  delete[] arr;
  return 0;
}
```