#include <iostream>

/*
arr <- array
start <- start index of array
end <- last index of array

parition(arr, start, end)
        pivot <- arr[start]
        j <- start
        i <- start + 1
        for i to end
                if (arr[i] <= pivot)
                        j++;
                        swap(arr[i], arr[j])

        swap(&arr[j], &arr[start])
        return j


quicksort(arr, start, end)
        if start >= end
                return
        index = parition(arr, start, end)

        quicksort(arr, start, index - 1)
        quicksort(arr, index + 1, end)


n1 <- first number
n2 <- second number
swap(n1, n2)
        temp = n1
        n1 = n2
        n2 = temp

*/
void swap(int *n1, int *n2) {

  int temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

int parition(int arr[], int start, int end) {

  int pivot = arr[start];
  int j = start;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot) {
      j++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[j], &arr[start]);
  return j;
}
void quicksort(int arr[], int start, int end) {

  if (start >= end)
    return;
  std::cout << start << " " << end << "\n";

  int index = parition(arr, start, end);
  std::cout << index << "\n";

  quicksort(arr, start, index - 1);
  quicksort(arr, index + 1, end);
}
int main(void) {

  // int arr[] = {1, 3, 6, 1, 54, 3, 32, 424, 1, 0, 320, 382, 231};

  int arr[]{1, 5, 2, 902, 123, 4, 154, 12};
  int length = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, 0, length - 1);

  for (auto x : arr)
    std::cout << x << " ";
  return 0;
}
