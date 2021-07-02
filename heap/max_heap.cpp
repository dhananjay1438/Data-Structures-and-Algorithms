#include <array>
#include <iostream>
#define SIZE 11

void max_heapify(std::array<int, SIZE> &arr, int i) {

  int largest = i;
  int left = i * 2;
  int right = (i * 2) + 1;

  if ((left < SIZE) && arr.at(left) > arr.at(i)) {
    largest = left;
  } else {
    largest = i;
  }
  if ((right < SIZE) && arr.at(right) > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    int temp = arr.at(largest);
    arr[largest] = arr[i];
    arr[i] = temp;
    max_heapify(arr, largest);
  }
}

void build_heap(std::array<int, SIZE> &arr) {
  for (int i = (arr.size() / 2); i > 0; i--) {
    max_heapify(arr, i);
  }
}

int main(void) {

  std::array<int, SIZE> arr{0, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16};
  build_heap(arr);
  for (int i = 1; i <= 10; i++) {

    std::cout << arr[i] << " ";
  }

  return 0;
}
