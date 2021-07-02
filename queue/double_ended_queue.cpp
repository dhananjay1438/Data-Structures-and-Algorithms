#include <iostream>
#include <vector>

#define SIZE 5

class Queue
{
    std::vector<int> m_queue;
    int m_front;
    int m_rear;

    public:
    Queue();
    void add_front(int);
    void add_rear(int);
    int remove_front();
    int remove_rear();
    void display();
};

Queue::Queue(): m_queue(SIZE), m_front(-1), m_rear(-1) {}

void Queue::add_front(int element)
{
    int val = -1;
    if (m_front == 0)
    {
        std::cout << "Cannot add from front as it is full\n";
        return;
    }
    else if (m_rear == -1 && m_front == -1)
    {
        // If list is empty
        m_front = m_rear = 0;
    }
    else
    {

        m_front--;
        val = m_front;
    }
    m_queue.at(val) = element;
}

void Queue::add_rear(int element)
{
    if (m_rear == SIZE - 1)
    {
        std::cout << "FULL\n";
        return;
    }
    if (m_front == -1 && m_rear == -1)
    {
        m_front = m_rear = 0;
    }
    else
    {
        m_rear++;
    }
    m_queue.at(m_rear) = element;
}

int Queue::remove_front()
{
    int val = -1;
    if (m_front == -1 && m_rear == -1)
    {
        std::cout << "EMPTY\n";
        return val;
    }
    else if (m_front == m_rear)
    {
        val = m_front;
        m_front = m_rear = -1;
    }
    else
    {
        val = m_front;
        m_front++;
    }
    return m_queue.at(val);
}
int Queue::remove_rear()
{
    return -1;
}

void Queue::display()
{
    if (m_rear == -1)
    {
        std::cout << "Alredy empty\n";
    }
    else
    {
        for (int i = m_front; i <= m_rear; i++)
        {
            std::cout << m_queue.at(i) << " ";
        }
        std::cout << "\n";
    }
}
int main(void)
{

    Queue queue;

    queue.add_rear(10);
    queue.add_rear(20);
    queue.add_rear(30);
    queue.add_rear(40);
    queue.display();

    std::cout << queue.remove_front() << std::endl;
    std::cout << queue.remove_front() << std::endl;

    queue.add_front(300);
    queue.add_front(500);
    queue.add_front(100);
    std::cout << "added\n";
    std::cout << queue.remove_front() << "\n";
    queue.display();

    queue.add_rear(20);

    queue.display();

    queue.add_rear(3000);

    queue.remove_front();
    queue.add_front(101);
    queue.display();


    return 0;
}
