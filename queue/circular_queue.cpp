// Runs only with c++17 and above
#include <array>
#include <iostream>
#include <variant>

#define SIZE 3

template <class T> class Queue {
private:
  int _front;
  int _rear;
  std::array<T, SIZE> queue;

public:
  Queue();
  T front();
  bool empty();
  bool full();
  void enqueue(T);
  void dequeue();
  void print();
};

template <class T> Queue<T>::Queue() : _front(-1), _rear(-1) {}

template <class T> T Queue<T>::front() { return queue.at(_front); }

template <class T> bool Queue<T>::empty() {
  if (_front == -1) {
    return true;
  }
  return false;
}
template <class T> bool Queue<T>::full() {
  if (_rear == SIZE - 1 && _front == 0) {
    return true;
  } else if (_front == _rear + 1) {
    return true;
  }
  return false;
}

template <class T> void Queue<T>::enqueue(T element) {
  if (full()) {
    std::cout << "Queue is full!\n";
    return;
  }
  if (_rear == -1) {
    _rear = _front = 0;
    queue.at(_rear) = element;
  } else {
    _rear = (_rear + 1) % SIZE;
    queue.at(_rear) = element;
  }
}

template <class T> void Queue<T>::dequeue() {
  if (empty()) {
    std::cout << "Queue is empty!\n";
    return;
  }
  if (_front == _rear) {
    _front = _rear = -1;
  } else {
    _front = (_front + 1) % SIZE;
  }
}
template <class T> void Queue<T>::print() {
  for (auto x : queue) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

int main(void) {
  Queue<std::variant<int, std::string>> q;

  q.enqueue(50);
  q.enqueue("some string");

  std::visit([](const auto &x) { std::cout << x; }, q.front());
  q.dequeue();
  std::visit([](const auto &x) { std::cout << x; }, q.front());
  return 0;
}
