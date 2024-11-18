 Algorithm for Insertion in an AVL Tree

Define Node Structure:
Each node in the AVL tree has:
key: The value of the node.
left: A pointer to the left child node.
right: A pointer to the right child node.
height: The height of the node, initialized to 1.

Height Function:
The height of a node is the number of edges from the node to the farthest leaf.
If the node is NULL, its height is considered as 0.
The height of a node is the maximum of the heights of its left and right subtrees, plus 1.
   
Rotation Functions:
Right Rotation (used to fix a Left-Left imbalance):
A right rotation is performed when the left subtree of a node is higher than its right subtree, leading to imbalance.
The rotation involves moving the left child up to take the current node's place, and the current node becomes the right child of its left child.
Left Rotation (used to fix a Right-Right imbalance):
A left rotation is performed when the right subtree of a node is higher than its left subtree.
The rotation involves moving the right child up to take the current node's place, and the current node becomes the left child of its right child.
   
Balance Factor:
The balance factor of a node is the difference between the height of its left and right subtrees.
If the balance factor is 1 or -1, the node is balanced.
If the balance factor is greater than 1 or less than -1, the node is unbalanced and needs rotation to restore balance.
   
Insert Function:
The insertion process in an AVL tree follows the same principle as a regular Binary Search Tree (BST):
If the key to be inserted is less than the current node's key, insert the key in the left subtree.
If the key is greater, insert it in the right subtree.
If the key is equal to the current node's key, the node is not inserted (duplicate keys are not allowed).
After inserting the key, the height of the current node is updated.
The balance factor of the current node is checked. If the node is unbalanced:
Left-Left Case: Perform a right rotation.
Right-Right Case: Perform a left rotation.
Left-Right Case: First perform a left rotation on the left child, then a right rotation on the current node.
Right-Left Case: First perform a right rotation on the right child, then a left rotation on the current node.
  
Preorder Traversal:
Preorder traversal is used to print the tree after inserting the nodes.
In preorder traversal, the current node is visited first, followed by recursively visiting the left and right subtrees.
  
Steps to Insert into AVL Tree:
Start with an empty tree (root is NULL).
Insert a key into the tree following the BST insertion rules.
After each insertion, update the height of the node and check if the tree is balanced.
If the tree is unbalanced, perform the necessary rotations to restore balance.
  
Example:
Insert keys into the AVL tree: 10, 20, 30, 40, 50, 25.
After inserting all keys, the tree is balanced using rotations where necessary.
Perform a preorder traversal to display the final AVL tree. The result will be a balanced tree, with the output showing the nodes in preorder sequence.

#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
    int key; 
    Node *left; 
    Node *right; 
    int height; 

    Node(int k) { 
        key = k; 
        left = nullptr; 
        right = nullptr; 
        height = 1; 
    }
}; 
int height(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return N->height; 
}
Node *rightRotate(Node *y) { 
    Node *x = y->left; 
    Node *T2 = x->right;  
    x->right = y; 
    y->left = T2;  
    y->height = 1 + max(height(y->left), 
                    height(y->right)); 
    x->height = 1 + max(height(x->left), 
                        height(x->right)); 
    return x; 
} 
Node *leftRotate(Node *x) { 
    Node *y = x->right; 
    Node *T2 = y->left; 

    y->left = x; 
    x->right = T2; 

    x->height = 1 + max(height(x->left), 
                        height(x->right)); 
    y->height = 1 + max(height(y->left), 
                        height(y->right)); 
    return y; 
} 
int getBalance(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
Node* insert(Node* node, int key) { 
    if (node == nullptr) 
        return new Node(key); 

    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else 
        return node;  
    node->height = 1 + max(height(node->left),
                           height(node->right)); 
    int balance = getBalance(node); 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
    if (balance > 1 && key > node->left->key) { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 

    // Right Left Case 
    if (balance < -1 && key < node->right->key) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    }  
    return node; 
} 
void preOrder(Node *root) { 
    if (root != nullptr) { 
        cout << root->key << " "; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
int main() { 
    Node *root = nullptr;  
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 

    cout << "Preorder traversal : \n"; 
    preOrder(root); 
    
    return 0; 
} 
