#include <iostream>

#define SIZE 10

class Queue {

private:
  int job[SIZE];
  int rear = -1;
  int front = 0;

public:
  bool is_full() {
    if (rear == SIZE - 1)
      return true;
    else
      return false;
  }

  bool is_empty() {
    if (front == -1 || front > rear)
      return true;
    else
      return false;
  }
  void enqueue(int data) {

    if (is_full()) {
      std::cout << "It is full!";
      return;
    }
    job[++rear] = data;
  }
  int dequeue() {
    if (is_empty()) {
      std::cout << "Already empty!";
      return -1;
    }
    return job[++front];
  }
};

int main(void) {
  Queue q;
  int choice = 0;
  do {

    std::cout << "1. Add element to queue\n";
    std::cout << "2. Remove element from the queue\n";
    std::cout << "-1. Quit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
  } while (choice != -1);
  return 0;
}
