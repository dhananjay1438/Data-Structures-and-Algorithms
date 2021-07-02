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
    void enqueue(int);
    int dequeue();
	void display();
};

Queue::Queue() : m_queue(SIZE), m_front(-1), m_rear(-1) {}

void Queue::enqueue(int x)
{

    if (m_rear == SIZE - 1)
    {
        std::cout << "Full\n";
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
    m_queue.at(m_rear) = x;

}
int Queue::dequeue() {

	int val = -1;
	if (m_front == -1 && m_rear == -1) {
		std::cout << "Empty\n";
		return val;
	}
	if (m_front == m_rear) {
		val = m_front;
		m_front = m_rear = -1;
	}
	else {
		val = m_front;
		m_front++;
	}
	return m_queue[val];
}
void Queue::display(){
	for (int i = m_front; i <= m_rear; i++) {
		std::cout << m_queue.at(i) << " ";
	}
}
int main(void)
{

	Queue queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.display();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();

	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(10);
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(200);
	queue.enqueue(10);
	queue.enqueue(20);
	queue.display();
	


    return 0;
}
