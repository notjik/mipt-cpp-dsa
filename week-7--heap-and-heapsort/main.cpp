#include <iostream>
#include <cstdint>

int PartitionHoar(int** arr, int left, int right) {
  int mid = (left + right) / 2;
  int pivot = arr[mid][1] + arr[mid][2] + arr[mid][3];
  while (left < right) {
    while (arr[left][1] + arr[left][2] + arr[left][3] > pivot) {
      left++;
    }
    while (arr[right][1] + arr[right][2] + arr[right][3] < pivot) {
      right--;
    }
    if (left >= right) {
      break;
    }
    int* temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    left++;
    right--;
  }
  return right;
}

void QuickSortHoar(int** arr, int left, int right) {
  if (left < right) {
    int pivotIndex = PartitionHoar(arr, left, right);
    QuickSortHoar(arr, left, pivotIndex);
    QuickSortHoar(arr, pivotIndex + 1, right);
  }
