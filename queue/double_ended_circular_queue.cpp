#include <array>
#include <iostream>
#define SIZE 5

class CircularDqueue {

private:
  std::array<int, SIZE> queue;

protected:
  int _front;
  int _rear;

public:
  CircularDqueue();
  int front();
  int rear();
  void add_front(int);
  void add_rear(int);
  void remove_front();
  void remove_rear();
};
CircularDqueue::CircularDqueue() : _front(-1), _rear(-1) {}

int CircularDqueue::front() { return queue.at(_front); }

int CircularDqueue::rear() { return queue.at(_rear); }

void CircularDqueue::add_rear(int element) {
  if (_rear == SIZE - 1 && _front == 0 && (_front == (_rear + 1) % SIZE)) {
    std::cout << "Rear is full!\n";
    return;
  }
  if (_front == -1 && _rear == -1) {
    _front = _rear = 0;
  } else {
    _rear = (_rear + 1) % SIZE;
  }
  queue.at(_rear) = element;
}

void CircularDqueue::remove_front() {
  if (_rear == _front) {
    _rear = _front = -1;
    std::cout << "Front empty!\n";
    return;
  }
  _front = (_front + 1) % SIZE;
}

void CircularDqueue::add_front(int element) {
  if (_front == (_rear + 1) % SIZE) {
    std::cout << "Front is full!\n";
    return;
  }
  if (_front == 0) {
    _front = SIZE - 1;
  }
  _front--;
  queue.at(_front) = element;
}

void CircularDqueue::remove_rear() {
  if (_rear == _front) {
    _rear = _front = -1;
    std::cout << "Rear empty!\n";
    return;
  }
  if (_rear == 0) {
    _rear = SIZE - 1;
  }
  _rear--;
}

int main(void) {
  CircularDqueue queue;
  queue.add_rear(50);
  queue.add_rear(50);
  queue.add_rear(50);
  queue.add_rear(50);
  queue.add_rear(50);
  queue.add_rear(10);
  queue.add_front(10);
  queue.remove_front();

  return 0;
}
