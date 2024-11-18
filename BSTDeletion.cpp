Define Node Structure:
A node in the BST is represented as:
key: The value stored in the node.
left: A pointer to the left child.
right: A pointer to the right child.
  
Find the Inorder Successor:
If the node to be deleted has two children, the inorder successor is the smallest node in its right subtree.
  
To find the successor:
Start from the node's right child.
Move left continuously until no left child exists.
The resulting node is the inorder successor.

Delete a Node:
Start from the root node and traverse the BST.
If the value to be deleted (x) is:
Less than the current node’s key: Recur on the left subtree.
Greater than the current node’s key: Recur on the right subtree.
Equal to the current node’s key:
Case 1: The node has no left child.
Replace the node with its right child.
Delete the node.
Case 2: The node has no right child.
Replace the node with its left child.
Delete the node.
Case 3: The node has two children.
Find the inorder successor of the node.
Replace the node’s key with the successor’s key.
Delete the successor node from the right subtree.
Perform Inorder Traversal:

To verify the BST after deletion, perform an inorder traversal:
Start from the root node.
Recursively visit the left subtree.
Print the current node's key.
Recursively visit the right subtree.
  
Driver Code:
Create the BST by inserting nodes.
Call the delete function to remove a specific key.
Perform an inorder traversal to display the updated BST.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
Node* getSuccessor(Node* curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}
Node* delNode(Node* root, int x)
{
    if (root == NULL)
        return root;
    if (root->key > x)
        root->left = delNode(root->left, x);
    else if (root->key < x)
        root->right = delNode(root->right, x);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* succ = getSuccessor(root);
        root->key = succ->key;
        root->right = delNode(root->right, succ->key);
    }
    return root;
}

void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 15;

    root = delNode(root, x);
    inorder(root);
    return 0;
}


  
