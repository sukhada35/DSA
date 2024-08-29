#include <iostream>
using namespace std;

class LinearQueue 
{
private:
    int front, rear, capacity;
    int *queue;

public:
    LinearQueue(int size) 
    {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    void enqueue(int data) 
    {
        if (rear == capacity - 1) 
        {
            cout << "Queue is full, can't add more customers." << endl;
            return;
        } 
        else if (front == -1) 
        {
            front = 0;
        }
        queue[++rear] = data;
        cout << "Customer " << data << " joined the queue." << endl;
    }

    void dequeue() 
    {
        if (front == -1 || front > rear) 
        {
            cout << "Queue is empty, no customers to serve." << endl;
            return;
        }
        cout << "Customer " << queue[front++] << " has been served." << endl;
    }

    void displayQueue() 
    {
        if (front == -1) 
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue: ";
        for (int i = front; i <= rear; i++) 
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    LinearQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.displayQueue();

    queue.dequeue();
    queue.displayQueue();

    queue.enqueue(4);
    queue.displayQueue();

    return 0;
}
