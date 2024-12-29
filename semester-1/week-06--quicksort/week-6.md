## Сортировка метолом Хоара
```c++
#include <iostream>

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int Partition(int* arr_, int left, int right) {
  int pivot = arr_[(left + right) / 2];
  while (left < right) {
    while (arr_[left] < pivot) {
      left++;
    }
    while (arr_[right] > pivot) {
      right--;
    }
    if (left <= right) {
      Swap(arr_[left], arr_[right]);
      left++;
      right--;
    }
  }
  return left;
}

void QuickSort(int* arr_, int left, int right) {
  if (left < right) {
    int pivotIndex = Partition(arr_, left, right);
    QuickSort(arr_, left, pivotIndex - 1);
    QuickSort(arr_, pivotIndex + 1, right);
  }
}
int main() {
  int n;
  std::cin >> n;
  int* arr_ = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr_[i];
  }
  QuickSort(arr_, 0, n - 1);

  std::cout << "Sorted array:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr_[i] << " ";
  }

  delete[] arr_;
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

int Partition(int* arr_, int left, int right) {
  int pivot = arr_[right];
  int i = (left - 1);

  for (int j = left; j < right; j++) {
    if (arr_[j] < pivot) {
      i++;
      Swap(arr_[i], arr_[j]);
    }
  }

  Swap(arr_[i + 1], arr_[right]);
  return i + 1;
}

void QuickSort(int* arr_, int left, int right) {
  if (left < right) {
    int pivotIndex = Partition(arr_, left, right);
    QuickSort(arr_, left, pivotIndex - 1);
    QuickSort(arr_, pivotIndex + 1, right);
  }
}

int main() {
  int n;
  std::cin >> n;
  int* arr_ = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr_[i];
  }
  QuickSort(arr_, 0, n - 1);

  std::cout << "Sorted array:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr_[i] << " ";
  }

  delete[] arr_;
  return 0;
}
```