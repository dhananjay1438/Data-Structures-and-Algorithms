#include <algorithm>
#include <iostream>
#include <vector>

void merge(std::vector<int> &merged, std::vector<int> &left,
           std::vector<int> &right) {

  auto left_iterator = left.begin();
  auto right_iterator = right.begin();
  while (left_iterator != left.end() && right_iterator != right.end()) {

    if (*left_iterator < *right_iterator) {
      merged.push_back(*left_iterator);
      left_iterator++;
    } else {
      merged.push_back(*right_iterator);
      right_iterator++;
    }

    if (left_iterator != left.end()) {
      std::move(left_iterator, left.end(), merged.end());
    } else if (right_iterator != right.end()) {
      std::move(right_iterator, right.end(), merged.end());
    }
  }
  for (auto x : merged) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void mergesort(std::vector<int> &arr) {

  if (arr.size() <= 1) {
    return;
  }

  int mid = arr.size() / 2;
  std::vector<int> left(arr.begin(), arr.begin() + mid);
  std::vector<int> right(arr.begin() + mid, arr.end());

  // for (auto x : left) {
  //   std::cout << x << " ";
  // }
  // std::cout << "\n";

  // for (auto x : right) {
  //   std::cout << x << " ";
  // }

  mergesort(left);
  mergesort(right);

  merge(arr, left, right);
  // std::move(left.begin(), left.end(), arr.begin());
  // std::move()
  for (auto x : arr)
    std::cout << x << " ";
  std::cout << "\n";
}
int main(void) {

  std::vector<int> arr{324, 23, 4, 235, 13, 5, 22, 4, 531, 3};

  mergesort(arr);

  return 0;
}
