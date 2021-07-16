#include <array>
#include <iostream>

#define SIZE 4
class Dqueue {

private:
  std::array<int, SIZE> queue;

protected:
  int _front;
  int _rear;

public:
  Dqueue();
  int front();
  int rear();
  void add_front(int);
  void add_rear(int);
  void remove_front();
  void remove_rear();
  // Returns -1 if front is empty, 1 if rear is empty, returns 0 if is not
  // empty
  int empty();
  void display();
};
Dqueue::Dqueue() : _front(-1), _rear(-1) {}

int Dqueue::empty() {
  if (_front == 0) {
    std::cerr << "Front empty!\n";
    return -1;
  }
  if (_rear == 0) {
    std::cerr << "Rear empty\n";
    return 1;
    ;
  }
  return 0;
}

int Dqueue::front() { return queue.at(_front); }

int Dqueue::rear() { return queue.at(_rear); }

void Dqueue::add_front(int element) {
  if (_front == 0) {
    std::cerr << "Front is full!\n";
    return;
  }
  _front--;
  queue.at(_front) = element;
}

void Dqueue::add_rear(int element) {
  if (_rear == SIZE - 1) {
    std::cerr << "Rear is full!\n";
    return;
  }
  if (_rear == -1) {
    _rear = _front = 0;
  } else {
    _rear++;
  }
  queue.at(_rear) = element;
}

void Dqueue::remove_front() {
  if (_front == _rear) {
    std::cerr << "Front is empty\n";
    return;
  }
  _front++;
}

void Dqueue::remove_rear() {
  if (_rear == 0) {
    std::cerr << "Rear is empty\n";
    return;
  }
  _rear--;
}

void Dqueue::display() {
  for (size_t i = 0; i < queue.size(); i++) {
    std::cout << queue.at(i) << " ";
  }
  std::cout << "front = " << _front << "\nrear = " << _rear << "\n";
}

int main(void) {
  Dqueue queue;

  queue.add_rear(5);
  queue.add_rear(5);
  queue.add_rear(10);
  queue.add_rear(10);

  queue.remove_front();
  queue.display();

  queue.remove_front();
  queue.remove_front();
  queue.display();
  queue.remove_front();

  queue.add_front(50);
  queue.add_front(30);
  queue.add_front(30);
  queue.display();
  queue.add_front(30);
  return 0;
}
