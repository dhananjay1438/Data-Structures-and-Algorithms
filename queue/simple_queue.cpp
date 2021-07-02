#include <iostream>
#include <vector>

#define SIZE 5
class Queue {
    std::vector<int> queue;
    int front = -1;
    int rear = -1;

public:
    Queue()
        : queue(SIZE) {};
    bool is_full();
    bool is_empty();
    void enqueue(int);
    int dequeue();
    void display();
};

bool Queue::is_full()
{
    if (rear == SIZE - 1)
        return true;
    else
        return false;
}

bool Queue::is_empty()
{
    if (rear == -1 && front == -1)
        return true;
    else
        return false;
}
void Queue::enqueue(int x)
{

    if (is_full()) {
        std::cout << "Full";
        return;
    }
    if (is_empty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue.at(rear) = x;
}
void Queue::display()
{
    for (int i = front; i <= rear; i++) {
        std::cout << queue[i] << " ";
    }
}
int Queue::dequeue()
{

    int val = -1;
    if (is_empty()) {
        std::cout << "Empty";
        return -1;
    }
    if (front == rear) {
        val = queue.at(front);
        front = rear = -1;
    } else {
        val = queue.at(front);
        front++;
    }
    return val;
}
int main(void)
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    queue.enqueue(10);
    queue.enqueue(10);
    queue.enqueue(10);
    queue.enqueue(10);
    queue.enqueue(10);

    queue.display();
    queue.enqueue(20);

    return 0;
}
