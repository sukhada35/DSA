// 5.1 Question : Stack using Linked List
#include <iostream> 
using namespace std;  
class Node  
{ 
public: 
    int data; 
    Node* next; 
    Node(int value) 
    { 
        data = value; 
        next = nullptr; 
    } 
}; 
class Stack { 
private: 
    Node* top; 
public:
    Stack()
    {
        top = nullptr;
    }
    ~Stack() //destructor 
    { 
        while (!isEmpty())  
        { 
            pop(); 
        } 
    } 
    void push(int value)  
    { 
        Node* newNode = new Node(value); 
        newNode->next = top; 
        top = newNode; 
    } 
    void pop()  
    { 
        if (isEmpty())  
        { 
            cerr << "Stack underflow!" << endl; 
            return; 
        } 
        Node* temp = top; 
        top = top->next; 
        delete temp; 
    } 

    int peek() const  
    { 
        if (isEmpty())  
        { 
            cerr << "Stack is empty!" << endl; 
            return -1; 
        } 
        return top->data; 
    } 
    bool isEmpty() const  
    { 
        return top == nullptr; 
    } 
}; 

int main()  
{ 
    Stack s; 
    s.push(10); 
    cout << "Top element is: " << s.peek() << endl; // Output: 10
    s.push(20); 
    cout << "Top element is: " << s.peek() << endl; // Output: 20 
    s.push(30); 
    cout << "Top element is: " << s.peek() << endl; // Output: 30 
    s.pop(); 
    cout << "Top element after pop is: " << s.peek() << endl; // Output: 20 
    s.pop();
    s.pop(); 
    s.pop();  
    return 0;
}
