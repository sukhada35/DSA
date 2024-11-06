// Question: Implement functions to delete a node present at the beginning, end, and specific positions of a linked list. 
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
void InsertAtBeginning(Node* &head, int data) 
{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void InsertAtEnd(Node* &head, int data) 
{
    Node* newNode = new Node(data);
    if (head == NULL) 
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) //iterates to find the last node
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void InsertAtPosition(Node* &head, int data, int position) 
{
    if (position == 0) 
    {
        InsertAtBeginning(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; i++) 
    {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void DeleteAtBeginning(Node* &head)
{
    if(head == NULL)
    {
        cout<<"List is empty. Can't delete."<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void DeleteAtEnd(Node* &head)
{
    if(head == NULL)
    {
        cout<<"List is empty. Can't delete."<<endl;
        return;
    }
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
void DeleteAtPosition(Node* &head, int position)
{
    if(head == NULL)
    {
        cout<<"List is empty. Can't delete."<<endl;
        return;
    }
    if(position == 0)
    {
        DeleteAtBeginning(head);
        return;
    }
    Node* temp = head;
    for(int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
    {
        cout<<"Position out of bounds"<<endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 10);
    InsertAtEnd(head, 40);
    InsertAtEnd(head, 50);
    InsertAtPosition(head, 25, 2);
    cout<<"Linked list before deletions: ";
    display(head);

    DeleteAtBeginning(head);
    cout<<"Linked list after deleting at the beginning: ";
    display(head);

    DeleteAtEnd(head);
    cout<<"Linked list after deleting at the end: ";
    display(head);

    DeleteAtPosition(head, 2);
    cout<<"Linked list after deleting at position 2: ";
    display(head);

    return 0;
}

