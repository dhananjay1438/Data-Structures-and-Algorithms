#include <array>
#include <iostream>

#define SIZE 10

class Heap {
private:
  void min_heapify(int);
  void max_heapify(int);
  void display();

protected:
  int position;
  std::array<int, SIZE> heap;
  void build_heap(bool);

public:
  virtual void push(int) = 0;
  virtual int pop() = 0;
  Heap();
  void insert(int, bool);
  int remove(bool);
};

Heap::Heap() : position(0) { heap[0] = -1; }

void Heap::display() {
  std::cout << "\n";
  for (int i = 1; i < position; i++) {
    std::cout << heap[i] << " ";
  }
  std::cout << "\n";
}
void Heap::insert(int key, bool max) {
  if (position == SIZE - 1) {
    std::cout << "Full!\n";
    return;
  }
  position++;
  heap[position] = key;
  build_heap(max);
}
int Heap::remove(bool max) {
  if (position == 0) {
    return -1;
  }
  int temp = heap[1];
  heap[1] = heap[position];
  position--;
  build_heap(max);
  return temp;
}
void Heap::min_heapify(int i) {

  int left = 2 * i;
  int right = 2 * i + 1;

  int min = i;
  if (left <= position && heap[left] < heap[i]) {
    min = left;
  }
  if (right <= position && heap[right] < heap[min]) {
    min = right;
  }
  if (min != i) {
    std::swap(heap[min], heap[i]);
    min_heapify(min);
  }
}
void Heap::build_heap(bool max) {
  if (max) {
    for (int i = position / 2; i > 0; i--) {
      max_heapify(i);
    }
  } else {
    for (int i = position / 2; i > 0; i--) {
      min_heapify(i);
    }
  }
}
void Heap::max_heapify(int i) {
  int max = i;

  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= position && heap[left] > heap[i]) {
    max = left;
  }
  if (right <= position && heap[right] > heap[max]) {
    max = right;
  }
  if (max != i) {
    std::swap(heap[max], heap[i]);
    max_heapify(max);
  }
}

class PriorityQueue : public Heap {
public:
  void push(int);
  int pop();
  int front();
  bool empty();
};

void PriorityQueue::push(int key) { insert(key, false); }
int PriorityQueue::pop() { return remove(false); }
bool PriorityQueue::empty() {
  if (position == 1) {
    return true;
  }
  return false;
}

int main(void) {
  PriorityQueue q;
  q.push(100);
}
