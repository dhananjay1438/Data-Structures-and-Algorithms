#include <algorithm>
#include <array>
#include <iostream>

std::array<int, 5> bubble_sort(std::array<int, 5> arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
  return arr;
}
int main(void) {

  std::array<int, 5> arr{234, 425, 354, 523, 4132};

  arr = bubble_sort(arr);

  for (auto &x : arr) {
    std::cout << x << " ";
  }

  return 0;
}
