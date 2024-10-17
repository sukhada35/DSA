// Write a C/C++ program to implement DFS traversals (All three) on binary tree

#include <iostream>
using namespace std;
class Node {
public:
    int data;         
    Node* left;       
    Node* right;      
 
    // Constructor to initialize the node
    Node(int val) 
    {
        data = val;   
        left = nullptr;  
        right = nullptr; 
    }
};
 
class BinaryTree {
public:
    Node* root;      
 
    // Constructor to initialize the binary tree
    BinaryTree() 
    {
        root = nullptr; // Start with an empty tree
    }
 
    // Pre-order traversal
    void PreOrderTraversal(Node* node) 
    {
        if (node == nullptr) 
        {
            return; // Base case: if the node is null, return
        }
        cout << node->data << " "; // Visit the node
        PreOrderTraversal(node->left); // Traverse left
        PreOrderTraversal(node->right); // Traverse right
    }
 
    // In-order traversal
    void InOrderTraversal(Node* node) 
    {
        if (node == nullptr) 
        {
            return; // Base case: if the node is null, return
        }
        InOrderTraversal(node->left); // Traverse left
        cout << node->data << " "; // Visit the node
        InOrderTraversal(node->right); // Traverse right
    }
 
    // Post-order traversal
    void PostOrderTraversal(Node* node) 
    {
        if (node == nullptr) 
        {
            return; // Base case: if the node is null, return
        }
        PostOrderTraversal(node->left); // Traverse left
        PostOrderTraversal(node->right); // Traverse right
        cout << node->data << " "; // Visit the node
    }
};
 
// Function to create a sample tree
Node* createSampleTree() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    return root;
}
 
int main() 
{
    BinaryTree tree;
    tree.root = createSampleTree(); // Create and assign the sample tree
 
    cout << "Pre-order traversal: ";
    tree.PreOrderTraversal(tree.root);
    cout << endl; // 5 3 2 4 7 6 8  
 
    cout << "In-order traversal: ";
    tree.InOrderTraversal(tree.root);
    cout << endl; // 2 3 4 5 6 7 8
 
    cout << "Post-order traversal: ";
    tree.PostOrderTraversal(tree.root);
    cout << endl; //2 4 3 6 8 7 5
    return 0;
}
