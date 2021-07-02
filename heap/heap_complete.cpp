#include <iostream>
#include <vector>

class Heap {

  int current_postiton;
  std::vector<int> heap;
  void swap(int &, int &);

public:
  Heap();
  void max_heapify(int);
  void min_heapify(int);
  void build_heap();
  void insert(int);
  void remove();
  void heapsort();
  void show();
};

Heap::Heap() {
  heap.push_back(-1);
  current_postiton = 0;
}

void Heap::swap(int &n1, int &n2) {

  int temp = n1;
  n1 = n2;
  n2 = temp;
}

void Heap::max_heapify(int i) {

  int largest = i;

  int size = current_postiton + 1;
  int left = 2 * i;
  int right = (2 * i) + 1;

  if ((left < size) && heap.at(left) > heap.at(i)) {
    largest = left;
  }
  if ((right < size) && heap.at(right) > heap.at(largest)) {
    largest = right;
  }
  if (largest != i) {
    swap(heap.at(largest), heap.at(i));
    max_heapify(largest);
  }
}

void Heap::min_heapify(int i) {
  int smallest = i;

  int left = i * 2;
  int right = (i * 2) + 1;
  int size = current_postiton;

  if ((left < size) && heap.at(left) < heap.at(i)) {
    smallest = heap.at(i);
  }
  if ((right < size) && heap.at(right) < heap.at(smallest)) {
    smallest = right;
  }
  if (smallest != i) {
    swap(heap.at(smallest), heap.at(i));
    min_heapify(smallest);
  }
}

void Heap::build_heap() {

  int mid = heap.size() / 2;
  for (int i = mid; i > 0; i--) {
    max_heapify(i);
  }
}

void Heap::insert(int element) {
  current_postiton++;
  heap.push_back(element);
  build_heap();
}

void Heap::remove() {
  int temp = heap.at(current_postiton);
  heap.at(current_postiton) = heap.at(1);
  heap.at(1) = temp;
  current_postiton--;
  build_heap();
}

void Heap::heapsort() {
  while (current_postiton) {
    remove();
  }
  for (auto &x : heap) {
    if (x != -1) {
      std::cout << x << " ";
    }
  }
}

void Heap::show() {
  for (int i = 1; i <= current_postiton; i++) {
    std::cout << heap.at(i) << " ";
  }
}

int main(void) {
  Heap heap;

  heap.insert(10);
  heap.insert(20);
  heap.insert(15);
  heap.insert(30);
  heap.insert(40);
  heap.show();
  std::cout << "\n";
  heap.heapsort();
  return 0;
}
