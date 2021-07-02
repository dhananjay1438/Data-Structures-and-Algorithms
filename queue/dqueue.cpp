#include <iostream>
#define SIZE 10
class DoubleQueue {

private:
  int queue[SIZE];
  int front = -1;
  int rear = -1;

public:
  void add_front(int);
  void add_rear(int);
  int remove_front();
  int remove_rear();
  bool is_full();
  bool is_empty();
};

bool DoubleQueue::is_full() {

  if ((front == 0 && rear == SIZE - 1) || front == rear + 1)
    return true;
  else
    return false;
}
bool DoubleQueue::is_empty() {
  if (front == -1)
    return true;
  else
    return false;
}

void DoubleQueue::add_rear(int data) {
  if (is_full()) {
    std::cout << "Its full!";
    return;
  }
  if (front == -1)
    front = rear = 0;
  else if (rear == SIZE - 1)
    rear = 0;
  else
    rear++;
  queue[rear] = data;
}
void DoubleQueue::add_front(int data) {
  if (is_full()) {
    std::cout << "It's full";
    return;
  }
  if (front == -1)
    front = rear = 0;
  else if (front == 0)
    front = SIZE - 1;
  else
    front--;

  queue[front] = data;
}
int DoubleQueue::remove_rear() {
  if (is_empty()) {
    std::cout << "It's empty!";
    return -1;
  }
  int temp = queue[rear];

  if (rear == front)
    rear = front = -1;

  else if (rear == 0)
    rear = SIZE - 1;
  else
    rear--;

  return temp;
}

int DoubleQueue::remove_front() {
  if (is_empty()) {
    std::cout << "It's empty";
    return -1;
  }

  int temp = queue[front];
  if (front == rear)
    front = rear = -1;
  else if (front == SIZE - 1)
    front = 0;
  else
    front++;

  return temp;
}
int main(void) {

  DoubleQueue q;

  return 0;
}
