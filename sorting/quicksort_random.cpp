#include <algorithm>
#include <iostream>
#include <vector>

void print_vec(std::vector<int> arr) {

  std::cout << "\n";
  for (auto &x : arr)
    std::cout << x << " ";
  std::cout << "\n";
}
std::vector<int>::iterator partition(std::vector<int> &arr) {

  auto j = arr.begin();
  auto i = arr.begin() + 1;
  int index = arr.size() / 2;
  int pivot = arr[index];
  std::iter_swap(arr.begin(), arr.begin() + index);

  for (; i != arr.end(); i++) {

    std::cout << "Value of *i = " << *i << " Value of pivot = " << pivot
              << "\n";

    if (*i <= pivot) {
      j++;
      std::cout << "Swapping " << *i << " " << *j << "\n";
      std::cout << "Array now:";
      std::iter_swap(i, j);
    }

    for (auto x : arr) {
      std::cout << x << " ";
    }
    std::cout << "\n";
    std::cout << "\n";
  }

  std::iter_swap(j, arr.begin());
  return j;
}
void quicksort(std::vector<int> &arr) {

  if (arr.size() <= 1) {
    return;
  }
  // Considering pivot as the middle element
  int pivot = (arr.size() / 2);

  std::cout << "\nSize of array = " << arr.size() - 1 << " Pivot = " << pivot
            << "\n";
  auto index = partition(arr);

  for (auto &x : arr)
    std::cout << x << " ";

  std::vector<int> left_array(arr.begin(), index);
  std::vector<int> right_array(index + 1, arr.end());

  quicksort(left_array);
  quicksort(right_array);

  std::move(left_array.begin(), left_array.end(), arr.begin());
  std::move(right_array.begin(), right_array.end(), index + 1);
  print_vec(arr);
}
int main(void) {

  // std::vector<int> arr{5, 4, 2, 1, 9};
  std::vector<int> arr{1, 5, 2, 902, 123, 4, 154, 12};
  std::cout << "Before: ";
  for (auto &x : arr) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  quicksort(arr);
  return 0;
}
