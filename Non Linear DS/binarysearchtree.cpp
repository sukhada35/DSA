#include <iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node* left;
    Node* right;
 
    Node(int value) 
    {
        data = value;    
        left = nullptr;    
        right = nullptr;   
    }
};
 
class BST {
private:
    Node* root;
 
    Node* insert(Node* node, int value) 
    {
        if (node == nullptr) //if null
        {
            return new Node(value); //create a new node
        }
        if (value < node->data) 
        {
            node->left = insert(node->left, value);
        } 
        else 
        {
            node->right = insert(node->right, value);
        }
        return node;
    }
 
    Node* findMin(Node* node) //find the left most child
    {
        while (node && node->left != nullptr) 
        {
            node = node->left;
        }
        return node;
    }
 
    Node* deleteNode(Node* node, int value) 
    {
        if (node == nullptr) return nullptr; //if null
 
        if (value < node->data) 
        {
            node->left = deleteNode(node->left, value);
        } 
        else if (value > node->data) 
        {
            node->right = deleteNode(node->right, value);
        } 
        else 
        {
            if (node->left == nullptr) 
            {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == nullptr) //node with one child
            {
                Node* temp = node->left;
                delete node;
                return temp;
            } 
            else 
            {
                Node* minNode = findMin(node->right);
                node->data = minNode->data; // Replace with min value
                node->right = deleteNode(node->right, minNode->data); // Delete min node
            }
        }
        return node;
    }
 
    // Helper function for in-order traversal
    void inOrderTraversal(Node* node) 
    {
        if (node != nullptr) 
        {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }
 
public:
    BST() : root(nullptr) {}
 
    // Public method to insert a value
    void insert(int value) 
    {
        root = insert(root, value);
    }
 
    // Public method to delete a value
    void deleteNode(int value) 
    {
        root = deleteNode(root, value);
    }
 
    // Public method for in-order traversal
    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }
};
 
int main() {
    BST tree;
    int choice, value;
 
    do {
        cout << "1. Insert a value\n";
        cout << "2. Delete a value\n";
        cout << "3. In-order traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
 
        switch (choice) 
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNode(value);
                break;
            case 3:
                cout << "In-order traversal: ";
                tree.inOrderTraversal();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
 
    return 0;
}