#include <array>
#include <iostream>
#define SIZE 11

void max_heapify(std::array<unsigned, SIZE> &arr, unsigned i) {

  unsigned largest = i;
  unsigned left = i * 2;
  unsigned right = (i * 2) + 1;

  if ((left < SIZE) && arr.at(left) > arr.at(i)) {
    largest = left;
  } else {
    largest = i;
  }
  if ((right < SIZE) && arr.at(right) > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    unsigned temp = arr.at(largest);
    arr[largest] = arr[i];
    arr[i] = temp;
    max_heapify(arr, largest);
  }
}

// This looks stupid actually 5 Oct 2021 21:53
// Extra time complexity for each addition of element into heap
void build_heap(std::array<unsigned, SIZE> &arr) {
  for (unsigned i = static_cast<unsigned>((arr.size() / 2)); i > 0; i--) {
    max_heapify(arr, i);
  }
}

int main(void) {

  std::array<unsigned, SIZE> arr{0, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16};
  build_heap(arr);
  for (unsigned i = 1; i <= 10; i++) {

    std::cout << arr[i] << " ";
  }

  return 0;
}
