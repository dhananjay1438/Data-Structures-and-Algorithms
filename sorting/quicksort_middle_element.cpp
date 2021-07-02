#include <iostream>
#include <vector>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
int parition(int arr[], int start, int end) {
  int j = start;
  // int elem = (start + end) / 2;
  int elem = start;
  int pivot = arr[elem];
  for (int i = start + 1; i <= end; i++) {

    if (arr[i] <= pivot) {
      j++;
      std::cout << "Swapping: " << arr[i] << " and " << arr[j] << "\n";
      swap(arr[i], arr[j]);
    }
  }
  std::cout << "Swapping for the last time: " << arr[j] << " and " << arr[elem]
            << "\n";
  swap(arr[j], arr[elem]);
  return j;
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

  //  int arr[] = {1, 5, 3, 7, 2, 9, 2};
  int arr[]{5, 4, 2};
  int length = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, 0, length - 1);
  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
