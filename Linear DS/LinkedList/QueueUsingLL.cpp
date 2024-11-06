#include <iostream> 
using namespace std; 
class Node 
{ 
public: 
    int data; 
    Node* next; 
    Node(int value = 0)
    {
        data = value;
        next = nullptr;
    }
}; 
class Queue 
{ 
private: 
    Node* front; 
    Node* rear; 
public: 
    Queue() 
    { 
        front = nullptr; 
        rear = nullptr; 
    }
    ~Queue() 
    { 
        while (!isEmpty()) 
        { 
            dequeue(); 
        } 
    } 
    void enqueue(int value) 
    { 
        Node* newNode = new Node(value); 
        if (rear) 
        { 
            rear->next = newNode; 
        } 
        else 
        { 
            front = newNode; 
        } 
        rear = newNode; // Update rear to the new node 
    } 
    void dequeue() 
    { 
        if (isEmpty()) 
        { 
            cerr << "Queue underflow!" << endl; 
            return; 
        } 
        Node* temp = front; 
        front = front->next; 
        if (front == nullptr) 
        { 
            rear = nullptr; 
        } 
        delete temp; 
    } 
    int peek() const 
    { 
        if (isEmpty()) 
        { 
            cerr << "Queue is empty!" << endl; 
            return -1; 
        } 
        return front->data; 
    } 
    bool isEmpty() const 
    { 
        return front == nullptr; 
    } 
}; 

int main() 
{ 
    Queue q; 
    int choice, value; 
    do 
    { 
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Check if Empty\n5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice)
        {
            case 1: 
                cout << "Enter value to enqueue: "; 
                cin >> value; 
                q.enqueue(value); 
                cout << value << " enqueued to queue." << endl; 
                break; 
            case 2: 
                if (!q.isEmpty()) 
                { 
                    cout << "Dequeuing front element: " << q.peek() << endl; 
                    q.dequeue(); 
                } 
                else 
                { 
                    cerr << "Queue is empty, cannot dequeue!" << endl; 
                } 
                break; 
            case 3: 
                if (!q.isEmpty()) 
                { 
                    cout << "Front element is: " << q.peek() << endl; 
                } 
                else 
                { 
                    cerr << "Queue is empty!" << endl; 
                } 
                break; 
            case 4: 
                if (q.isEmpty()) 
                { 
                    cout << "Queue is empty." << endl; 
                } else 
                { 
                    cout << "Queue is not empty." << endl; 
                } 
                break; 
            case 5: 
                cout << "Exiting..." << endl; 
                break; 
            default: 
                cerr << "Invalid choice. Please try again." << endl; 
                break; 
        } 
    } while (choice != 5); 
    return 0;
}
