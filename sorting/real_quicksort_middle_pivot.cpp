#include <algorithm>
#include <iostream>
#include <vector>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

static int comp = 0;
int parition(int arr[], int start, int end) {

  int mid = (start + end) / 2;
  // int pivot = arr[start];
  int pivot = arr[mid];
  swap(arr[mid], arr[start]);
  std::cout << "Pivot element = " << pivot << "\n";
  int counter_smaller = start;

  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot) {
      comp++;
      counter_smaller++;
      swap(arr[i], arr[counter_smaller]);
    }
  }
  swap(arr[counter_smaller], arr[start]);
  return counter_smaller;
}

void quicksort(int arr[], int start, int end) {
  if (start >= end) {
    return;
  }

  int index = parition(arr, start, end);

  quicksort(arr, start, index - 1);
  quicksort(arr, index + 1, end);
}
int main(void) {

  int arr[]{9, 8, 7, 6, 5};

  int length = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, 0, length - 1);

  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\ncomparisons = " << comp;
  return 0;
}
