//Ex 4.2 Implement circular queue
#include <iostream>
using namespace std;

class CircularQueue 
{
private:
    int front, rear, capacity;
    int *queue;

public:
    CircularQueue(int size) 
    {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    void enqueue(int data) 
    {
        if ((rear + 1) % capacity == front) 
        {
            cout << "Queue is full, can't add more customers." << endl;
            return;
        } 
        else if (front == -1) 
        {
            front = rear = 0;
        } 
        else 
        {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = data;
        cout << "Customer " << data << " joined the queue." << endl;
    }

    void dequeue() 
    {
        if (front == -1) 
        {
            cout << "Queue is empty, no customers to serve." << endl;
            return;
        }
        cout << "Customer " << queue[front] << " has been served." << endl;
        if (front == rear) 
        {
            front = rear = -1; // Queue becomes empty
        } 
        else 
        {
            front = (front + 1) % capacity;
        }
    }

    void displayQueue() 
    {
        if (front == -1) 
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue: ";
        int i = front;
        while (true) 
        {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() 
{
    CircularQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.displayQueue();

    queue.dequeue();
    queue.displayQueue();

    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.displayQueue();

    queue.dequeue();
    queue.displayQueue();

    return 0;
}
