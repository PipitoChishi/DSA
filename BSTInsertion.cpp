Algorithm:
1. Define the Node Structure:
Structure of a Node:
Each node contains:
A key (key) to store the value.
A left pointer (left) to reference the left child.
A right pointer (right) to reference the right child.
  
2. Insert a Key into the BST:
Input: A pointer to the root node (node) and the key to be inserted (key).
Output: The root node of the modified BST.
If the tree is empty (node == NULL):
Create a new node with the given key.
Set its left and right pointers to NULL.
Return the new node.
If the key is equal to the current node’s key:
Return the current node (no duplicates are allowed).
If the key is less than the current node’s key:
Recursively call the Insert function on the left subtree (node->left) with the same key.
Set the result of the recursive call as the left child of the current node.
If the key is greater than the current node’s key:
Recursively call the Insert function on the right subtree (node->right) with the same key.
Set the result of the recursive call as the right child of the current node.
Return the root node.
  
3. Perform Inorder Traversal of the BST:
Input: A pointer to the root node (node).
Output: Keys of the BST in sorted order (ascending).
If the current node is NULL, return (base case for recursion).
Recursively call the Inorder Traversal function on the left subtree (node->left).
Print the key of the current node.
Recursively call the Inorder Traversal function on the right subtree (node->right).

4. Main Program:
Input: A set of keys to be inserted into the BST.
Output: The BST keys printed in ascending order using inorder traversal.
Initialize the root of the BST as NULL.
For each key in the input:
Call the Insert function with the root node and the current key.
Update the root with the result of the function.
Call the Inorder Traversal function with the root node.

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;    
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* node, int key) {
    if (node == NULL) 
        return new Node(key);    
    if (node->key == key) 
        return node;
    if (node->key < key) 
        node->right = insert(node->right, key);
    else 
        node->left = insert(node->left, key);
    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}


int main() {
    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
  
    inorder(root);

    return 0;
}
