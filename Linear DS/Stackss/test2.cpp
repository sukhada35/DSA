#include<iostream>
using namespace std;
const int MAX_SIZE = 100;
class Stack
{
private:
    int stack[MAX_SIZE];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == MAX_SIZE - 1);
    }
    void push(int element)
    {
        if(isFull())
        {
            cout<<"Stack overflow. Can't push";
        }
        else
        {
            stack[++top] = element;
            cout<<"Pushed Element"<<element<<endl;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow. Can't pop";
        }
        else
        {
            cout<<"Element"<<stack[top--]<<"Is popped."<<endl;
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"No top element"<<endl;
            return -1;
        }
        else
        {
            return stack[top];
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No elements to display." << endl;
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; ++i)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Stack MyStack;
    int element;
    int choice;
    do
    {
        cout<<"Menu"<<endl;
        cout << "1. Push Element" << endl;
        cout << "2. Pop Element" << endl;
        cout << "3. Peek Element" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Exit" << endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the Element which needs to get pushed. "<<endl;
                cin>>element;
                MyStack.push(element);
                break;
            case 2:
                 MyStack.pop();
                 break;
            case 3:
                 MyStack.peek();
                 break;
            case 4:
                 MyStack.display();
                 break;
            case 5:
                 cout<<"GOODBYEEE";
                 break;
            default:
                cout<<"Invalid input";
        }
    } while (choice != 5);
 
    return 0;
}
