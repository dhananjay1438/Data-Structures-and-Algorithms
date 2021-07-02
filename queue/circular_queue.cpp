#include <iostream>
#include <vector>

#define SIZE 5

// Circular Queue
class CircularQueue {
    std::vector<int> queue;
    int front = 0;
    int rear = -1;

public:
    CircularQueue()
        : queue(SIZE)
    {
    }
    bool is_empty();
    bool is_full();
    void enqueue(int);
    int dequeue();
    void display();
};

bool CircularQueue::is_full() {
    if (rear == SIZE - 1  && front == 0) {
        return true;
    }
    else {
        return false;
    }
}
void CircularQueue::enqueue(int element)
{
    if (is_full()) {
        std::cout << "Queue full\n";
        return;
    }
    std::cout << "rear = " << rear << " front = " << front << "\n";
    if (rear == SIZE-1  && front != 0) {
        rear = 0;
        std::cout << "1st cond\n";
    }
    else if (front == rear + 1) {
        front = 0;
        rear = -1;
        std::cout << "2st cond\n";
    }
    rear++;
    queue.at(rear)= element;
}
int CircularQueue::dequeue()
{

    return -1;
}
void CircularQueue::display()
{
    for (auto &x: queue) {
        std::cout << x << " ";
    }
}
int main(void)
{

    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(10);
    queue.enqueue(20);


//	std::cout << queue.dequeue() << "\n";
//	std::cout << queue.dequeue() << "\n";

//	std::cout << queue.dequeue() << "\n";
//	std::cout << queue.dequeue() << "\n";

    queue.enqueue(200);
    queue.enqueue(300);

    std::cout << "Display: ";
    queue.display();

    return 0;
}
