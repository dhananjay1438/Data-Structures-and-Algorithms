#include <iostream>
int main(void) {
  int arr[5] = {1, 32, 5, 7, 1};
  int *ptr = arr;
  for (int i = 0; i < 5; i++) {
    std::cout << *(ptr + i);
  }
  return 0;
}
