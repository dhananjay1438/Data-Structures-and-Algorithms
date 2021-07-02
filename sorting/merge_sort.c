#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int start1, int end1, int start2, int end2) {

  int n1 = end1 - start1 + 1;
  int n2 = end2 - start2 + 1;
  int arr1[n1];
  int arr2[n2];
  for (int i = 0; i < n1; i++) {
    arr1[i] = arr[start1 + i];
  }
  for (int j = 0; j < n2; j++) {
    arr2[j] = arr[start2 + j];
  }

  int i = 0, j = 0;
  int k = start1;

  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j])
      arr[k] = arr1[i++];
    else
      arr[k] = arr2[j++];
    k++;
  }
  while (i < n1)
    arr[k++] = arr1[i++];

  while (j < n2)
    arr[k++] = arr2[j++];
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

  int arr[] = {10, 1, 402, 411, 890, 81, 40};
  int size = 7;

  merge_sort(arr, 0, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
