#include <stdio.h>

void merge_sort(int[], int, int);
void merge(int arr[], int start1, int end1, int start2, int end2) {

  int n1 = end1 - start1 + 1;
  int n2 = end2 - start2 + 1;
  // int temp[end2 - start1];
  printf("n1 = %d ", n1);
  int temp[end2];

  int i = start1, j = start2, k = start1;

  while (i <= end1 && j <= end2) {
    if (arr[i] < arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }
  while (i <= end1) {
    temp[k] = arr[i];
    k++;
    i++;
  }
  while (j <= end2) {
    temp[k] = arr[j];
    k++;
    j++;
  }
  for (int i = start1; i <= end2; i++) {
    arr[i] = temp[i];
  }
}
void merge_sort(int arr[], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, mid + 1, end);
  }
}

int main(void) {
  int arr[] = {1, 5, 6, 1, 6, 23, 87, 11, 54};
  int length = 8;
  merge_sort(arr, 0, length - 1);

  printf("\n");
  for (int i = 0; i < length; i++)
    printf("%d ", arr[i]);
  return 0;
}
