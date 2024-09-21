//Question: Implement functions to insert new elements at the beginning, end, and middle positions of a linked list.
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int value){
        data = value;
        next = NULL;
    }
    
    // Static function to create a new node
    static Node* createNode(int data) 
    {
        return new Node(data);
    }
};

void InsertAtBeginning(Node* &head, int data) 
{
    Node* newNode = Node::createNode(data);
    newNode->next = head;
    head = newNode;
}

void InsertAtEnd(Node* &head, int data) 
{
    Node* newNode = Node::createNode(data);
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

void InsertAtPosition(Node*& head, int data, int position) {
    if (position == 0) 
    {
        InsertAtBeginning(head, data);
        return;
    }

    Node* newNode = Node::createNode(data);
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

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() 
{
    Node* head = nullptr;

    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 10);
    cout << "Linked list after inserting at the beginning: ";
    displayList(head);

    InsertAtEnd(head, 40);
    InsertAtEnd(head, 50);
    cout << "Linked list after inserting at the end: ";
    displayList(head);

    InsertAtPosition(head, 25, 2);
    cout << "Linked list after inserting at position 2: ";
    displayList(head);

    return 0;
}



