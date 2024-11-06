//2.2 To sort data in stack using recursion ( Do not use secondary stack)
#include <iostream>
#include <stack>
using namespace std;
void sortedInsert(stack<int> &s, int element)  // insert an element in a sorted stack
{
    if (s.empty() || element >= s.top()) // 90>=8 
    {
        s.push(element);                 // 1 2 3 8 90
        return;
    }
    int top = s.top(); // 1 2 3 8 90(pop), 9 >= 90
    s.pop();
    sortedInsert(s, element); //after pushing 1 2 3 8 9
    s.push(top); //stored value will get pushed
}
// Function to sort the stack using recursion
void sortStack(stack<int> &s) 
{
    if (s.empty()) 
    {
        return;
    }
    int top = s.top(); //stores top value in top 1 2 3 8 9
    s.pop();
    sortStack(s); //it will pop until its empty
    sortedInsert(s, top); //stored value will get pushed 9 8 3 2 1
}
// Helper function to print stack
void printStack(stack<int> s) 
{
    while (!s.empty()) 
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main() 
{
    stack<int> s;
    int n;
 
    // Take number of elements input from the user
    cout << "Enter the number of elements in the stack: ";
    cin >> n; //5
 
    // Take elements input from the user
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        int element;
        cin >> element;
        s.push(element); // 1 2 3 4 5
    }
 
    cout << "Stack before sorting: ";
    printStack(s); //
    sortStack(s);
 
    cout << "Stack after sorting: ";
    printStack(s);
 
    return 0;
}
