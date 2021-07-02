#include <iostream>
#include <vector>

class PriorityQueueEmpty : public std::exception {
public:
  const char *what() const throw() { return "Queue is empty!"; }
};

class PriorityQueue {
  std::vector<int> heap;
  int current_position;

  void min_heapify(int);
  bool empty();

public:
  PriorityQueue();
  void push(int);
  void pop();
  int top();
};

PriorityQueue::PriorityQueue() {
  current_position = 0;
  heap.push_back(-1);
}

void PriorityQueue::push(int element) {
  current_position++;
  heap.push_back(element);
  min_heapify(1);
}

void PriorityQueue::pop() {

  try {
    if (!empty()) {
      heap.erase(heap.begin());
    } else {
      throw PriorityQueueEmpty();
    }
  } catch (PriorityQueueEmpty &e) {
    std::cout << e.what();
  } catch (...) {
    std::cout << "Some other exception";
  }
}

int PriorityQueue::top() { return heap.at(1); }

bool PriorityQueue::empty() {

  if (current_position == 0) {
    return true;
  }
  return false;
}

void PriorityQueue::min_heapify(int i) {

  int smallest = i;

  int left = i * 2;
  int right = i * 2 + 1;
  int length = current_position;

  if ((left <= length) && heap.at(left) < heap.at(i)) {
    smallest = left;
  }

  if ((right <= length) && heap.at(right) < heap.at(smallest)) {
    smallest = right;
  }

  if (smallest != i) {
    std::swap(heap.at(smallest), heap.at(i));
    min_heapify(smallest);
  }
}

int main(void) {

  PriorityQueue pq;

  pq.push(30);
  pq.push(20);
  pq.push(100);

  std::cout << pq.top();
  pq.pop();
  std::cout << pq.top();

  return 0;
}
