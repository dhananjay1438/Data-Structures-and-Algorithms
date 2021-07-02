#include <vector>
#include <iostream>

#define SIZE 5

class CircularQueue
{

    std::vector<int> m_queue;
    int m_front;
    int m_rear;

    public:
    CircularQueue();
    void enqueue(int);
    int peek();
    int deque();
    void display();
};
CircularQueue::CircularQueue() : m_queue(SIZE), m_front(-1), m_rear(-1) {}
void CircularQueue::enqueue(int x)
{

    //If is empty
    if (m_front == -1 && m_rear == -1)
    {
        m_front = m_rear = 0;
    }
    // If is full
    else if ((m_front == 0 && m_rear == SIZE - 1) || m_rear == m_front - 1)
    {
        std::cout << "Queue full\n";
        return;
    }
    // If elements are deleted from front
    else if (m_rear == SIZE - 1 && m_front != 0)
    {
        m_rear = 0;
    }
    else
    {
        m_rear++;
    }
    m_queue.at(m_rear) = x;
}
int CircularQueue::deque()
{
	int val = peek();
    // If queue is empty
    if (m_front == -1 && m_rear == -1)
    {
        std::cout << "Already empty\n";
    }
    // IF it's last element
    else if (m_front == m_rear)
    {
        m_front = m_rear = -1;
    }
    else if (m_front == SIZE - 1)
    {
        m_front = 0;
    }
    else
    {
        m_front++;
    }
    return val;
}

int CircularQueue::peek()
{
    if (m_front == -1)
    {
        return -1;
    }
    else
    {
       return  m_queue.at(m_front);
    }
}

void CircularQueue::display()
{

    for (auto x : m_queue)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main(void)
{

    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.deque();
    q.deque();
    q.enqueue(100); q.enqueue(200); q.display();

    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;

	std::cout << q.peek();

    return 0;
}
