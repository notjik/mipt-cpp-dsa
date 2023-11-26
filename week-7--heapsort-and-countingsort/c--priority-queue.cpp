#include <iostream>

void SiftUp(int* arr, int id) {
  while (id > 0) {
    int parent = (id - 1) / 2;
    if (arr[parent] < arr[id]) {
      std::swap(arr[parent], arr[id]);
      id = parent;
    } else {
      break;
    }
  }
  std::cout << id + 1 << '\n';
}

void SiftDown(int* arr, int n, int id) {
  while (id < n) {
    int child_1 = id * 2 + 1;
    int child_2 = id * 2 + 2;
    int id_max = id;
    if (child_1 < n && child_2 < n && (arr[child_1] > arr[id_max] || arr[child_2] > arr[id_max])) {
      id_max = (arr[child_1] >= arr[child_2] ? child_1 : child_2);
    } else if (child_1 < n && child_2 >= n && arr[child_1] > arr[id_max]) {
      id_max = child_1;
    }
    if (id_max != id) {
      std::swap(arr[id], arr[id_max]);
      id = id_max;
    } else {
      break;
    }
  }
  std::cout << id + 1 << " ";
}

void ExtractMax(int* arr, int& n) {
  std::swap(arr[0], arr[n - 1]);
  int del = arr[n - 1];
  n -= 1;
  if (n > 0) {
    SiftDown(arr, n, 0);
  } else {
    std::cout << "0 ";
  }
  std::cout << del << '\n';
}

void Push(int*& arr, int& capacity, int element) {
  arr[capacity] = element;
  SiftUp(arr, capacity);
  capacity += 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  auto* arr = new int[n];
  int capacity = 0;
  for (int i = 0; i < m; i++) {
    int command;
    std::cin >> command;
    if (command == 1) {
      if (capacity > 0) {
        ExtractMax(arr, capacity);
      } else {
        std::cout << "-1\n";
      }
    } else {
      int val;
      std::cin >> val;
      if (capacity < n) {
        Push(arr, capacity, val);
      } else {
        std::cout << "-1\n";
      }
    }
  }
  for (int i = 0; i < capacity; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}