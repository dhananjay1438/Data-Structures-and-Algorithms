#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int start, int mid, int end) {
  std::vector<int> pre(mid - start + 1), post(end - mid);
  std::cout << pre.size() << " " << post.size() << "\n";
  for (size_t i = 0; i < pre.size(); i++) {
    pre[i] = arr[start + i];
  }
  for (size_t j = 0; j < post.size(); j++) {
    post[j] = arr[mid + 1 + j];
  }

  size_t i = 0, j = 0;
  int k = start;
  while (i < pre.size() && j < post.size()) {
    if (pre[i] < post[j]) {
      arr[k] = pre[i];
      i++;
    } else {
      arr[k] = post[j];
      j++;
    }
    k++;
  }
  while (i < pre.size()) {
    arr[k] = pre[i];
    i++;
    k++;
  }
  while (j < post.size()) {
    arr[k] = post[j];
    j++;
    k++;
  }
}

void merge_sort(std::vector<int> &arr, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}
int main(void) {
  std::vector<int> arr = {1, 4, 2, 0, 9, 2, 34, 32, 652, 45, 23};
  merge_sort(arr, 0, arr.size() - 1);

  for (auto &x : arr) {
    std::cout << x << " ";
  }

  return 0;
}
