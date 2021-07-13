#include <array>
#include <iostream>

#define SIZE 5

class Queue {

private:
  std::array<int, SIZE> queue;

protected:
public:
  Queue();
  void enqueue(int);
  void dequeue();
  int front();
  int size();
  bool empty();
  bool full();
  int _rear;
  int _front;
};

Queue::Queue() : _rear(-1), _front(-1) {}

int Queue::size() { return queue.size(); }

bool Queue::empty() {
  if (_rear == -1) {
    return true;
  }
  return false;
}
bool Queue::full() {
  if (_rear == SIZE - 1) {
    return true;
  }
  return false;
}
void Queue::enqueue(int element) {
  if (full()) {
    std::cout << "Queue is full!\n";
    return;
  }
  if (_rear == -1) {
    _front = _rear = 0;
  } else {
    _rear++;
  }
  queue[_rear] = element;
}
void Queue::dequeue() {
  if (empty()) {
    std::cout << "Queue is empty\n";
    return;
  }
  if (_front == _rear) {
    _front = _rear = -1;
  } else {
    _front++;
  }
}
int Queue::front() {
  try {
    return queue.at(_front);
  } catch (std::out_of_range) {
    std::cerr << "Queue is empty ";
    return -1;
  }
}

int main(void) {
  Queue queue;

  queue.enqueue(50);
  queue.enqueue(30);
  queue.dequeue();
  queue.dequeue();

  std::cout << queue.front() << "\n";

  return 0;
}
