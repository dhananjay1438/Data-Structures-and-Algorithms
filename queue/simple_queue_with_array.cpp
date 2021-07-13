#include <array>
#include <iostream>

#define SIZE 2

class Queue {

private:
  std::array<int, SIZE> queue;

protected:
  int _rear;
  int _front;

public:
  Queue();
  void enqueue(int);
  void dequeue();
  int front();
  int size();
  bool empty();
  bool full();
};

Queue::Queue() : _rear(0), _front(0) {}

int Queue::size() { return queue.size(); }

bool Queue::empty() {
  if (_front == _rear) {
    return true;
  }
  return false;
}
bool Queue::full() {
  if (_rear == SIZE) {
    return true;
  }
  return false;
}
void Queue::enqueue(int element) {
  if (!full()) {
    queue[_rear] = element;
    _rear++;
  } else {
    std::cout << "Queue is full!\n";
  }
}
void Queue::dequeue() {
  if (!empty()) {
    _front++;
  } else {
    std::cout << "Queue is empty\n";
    _front = _rear = 0;
  }
}
int Queue::front() { return queue.at(_front); }

int main(void) {
  Queue queue;

  queue.enqueue(50);
  queue.enqueue(30);

  return 0;
}
