//Exp 3. Write a program in C++ to perform parenthesis check using stack
#include <iostream>
#include <string>
 
using namespace std;
 
const int MAX_SIZE = 100;
 
bool isBalanced(const string& expression) 
{
    char stack[MAX_SIZE];  
    int top = -1;  
 
    for (char ch : expression) 
    {
        // If the character is an opening parenthesis, push it onto the stack
        if (ch == '(' || ch == '[' || ch == '{') 
        {
            if (top >= MAX_SIZE - 1) 
            {
                cerr << "Stack overflow" << endl;
                return false; // Exceeded stack capacity
            }
            stack[++top] = ch;
        }
        // If the character is a closing parenthesis
        else if (ch == ')' || ch == ']' || ch == '}') 
        {
            if (top == -1) 
            {
                // Stack is empty but closing parenthesis found
                return false;
            }
            char topChar = stack[top--];
 
            // Check if the popped opening parenthesis matches the closing one
            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{')) 
            {
                return false;
            }
        }
    }
 
    // If the stack is empty, the expression is balanced
    return top == -1;
}
 
int main() {
    string expression;
 
    // Get the expression from the user
    cout << "Enter the expression to check: ";
    getline(cin, expression);
 
    // Check if the expression is balanced
    if (isBalanced(expression)) 
    {
        cout << "The expression is balanced." << endl;
    } 
    else 
    {
        cout << "The expression is not balanced." << endl;
    }
 
    return 0;
}
