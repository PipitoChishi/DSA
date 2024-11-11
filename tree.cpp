Write a program to create a binary tree. The program should allow the user to enter values for the root, left,
and right nodes recursively. After creating the tree, print the tree's values using preorder traversal.

Algorithm (Steps):
Create function (create()):

If the current node is empty, ask the user for a value and create a new node.
Ask if the user wants to add a left child.
If yes, recursively create the left child.
Ask if the user wants to add a right child.
If yes, recursively create the right child.
Return the current node.
Preorder Traversal function (printPreorder()):

Print the value of the current node.
Recursively call the function for the left child.
Recursively call the function for the right child.

#include <iostream>
using namespace std;

struct node {
    int value;
    node *left, *right;
};

void printPreorder(node *parent) {
    if (parent == nullptr)
        return;
    cout << parent->value << " -> ";
    printPreorder(parent->left);
    printPreorder(parent->right);
}

// Function to create the binary tree
node* create(node *parent) {
    if (parent == nullptr) {
        parent = new node;
        cout << "Enter the value: ";
        cin >> parent->value;
        parent->left = nullptr;
        parent->right = nullptr;
    }

    string choice;
    cout << "Do you want to enter this at the left? (y/n): ";
    cin >> choice;
    if (choice == "y") {
        parent->left = create(parent->left);  
    }

    cout << "Do you want to enter this at the right? (y/n): ";
    cin >> choice;
    if (choice == "y") {
        parent->right = create(parent->right); 
    }

    return parent;  
}

int main() {
    node *parent = nullptr;
    parent = create(parent); 
    
    cout << "Preorder Traversal of the tree: ";
    printPreorder(parent); 
    cout << endl;

    return 0;
}
