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
    void display();
    void add_rear(int);
    void add_front(int);
    int remove_rear();
    int remove_front();
    int peek(int);
};

Queue::Queue()
    : m_queue(SIZE)
    , m_front(-1)
    , m_rear(-1)
{
}

void Queue::display()
{

    if (m_front == -1)
    {
        std::cout << "Display() empty\n";
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            std::cout << m_queue.at(i) << " ";
        }
        std::cout << "\n";
    }
}

void Queue::add_rear(int element)
{

    if (m_rear == SIZE - 1)
    {
        // Overflow
        std::cout << "add_rear() full\n";
        return;
    }
    // If queue is empty
    else if (m_front == -1 && m_rear == -1)
    {
        m_front = m_rear = 0;
    }
    else
    {
        m_rear++;
    }
    m_queue.at(m_rear) = element;
}

void Queue::add_front(int element)
{

    int val = -1;
    // If queue is full i.e if elements can't be added from front end
    if (m_front == 0)
    {
        std::cout << "add_front() full\n";
        return;

    }
    // If list is empty or adding the element for the first time
    else if (m_front == -1 && m_rear == -1)
    {
        m_front = m_rear = 0;
    }
    else
    {
        m_front--;
        val = m_front;
    }
    m_queue.at(val) = element;
}

int Queue::peek(int front_or_rear) {
	return m_queue[front_or_rear];
}
int Queue::remove_rear()
{
	return -1;
	int val = -1;

	if (m_front == -1 && m_rear == -1) {
		std::cout << "remove_rear() Empty\n";
		return val;
	}
	// If there is only single element
	else if (m_front == m_rear){
		val = m_front;
		m_front = m_rear = -1;
	}
	else {
		val = m_front;
		m_front++;
	}
	return m_queue.at(val);
}
int Queue::remove_front()
{
	int val = -1;
    // If queue is empty
    if (m_front == -1 && m_rear == -1)
    {
        std::cout << "remove_front() empty\n";
        return val;
    }
    // If there is only one element left
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
