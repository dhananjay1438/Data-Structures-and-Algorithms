#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubble_sort(int arr[], int n) {
  if (n > 1) {
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1])
        swap(&arr[i], &arr[i + 1]);
    }
    bubble_sort(arr, n - 1);
  }
}

int main(void) {
  int arr[] = {1, 5, 7, 2, 7};
  int n = 5;
  bubble_sort(arr, n);
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}
