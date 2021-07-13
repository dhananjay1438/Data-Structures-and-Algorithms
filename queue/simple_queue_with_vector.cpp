#include <iostream>
#include <queue>
#include <vector>

class Queue {

private:
  std::vector<int> queue;

public:
  int size();
  bool empty();
  void enqueue(int);
  void dequeue();
  int front();
};

int Queue::size() { return queue.size(); }
bool Queue::empty() { return queue.empty(); }
void Queue::enqueue(int element) { queue.push_back(element); }
void Queue::dequeue() { queue.erase(queue.begin()); }
int Queue::front() { return queue.at(0); }

int main(void) {
  Queue q;
  q.enqueue(50);
  q.enqueue(30);
  q.enqueue(70);
  std::cout << q.front();
  q.dequeue();
  std::cout << q.front();
  return 0;
}
