//Create a simple linked list structure and write code to display its elements.
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL) //if not empty
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    display(head);
    return 0;
}