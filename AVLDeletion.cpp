Deletion Algorithm:
Find the Node to Delete:
If the root is NULL, return NULL (base case).
If the key to be deleted is smaller than the current node's key, move to the left subtree.
If the key to be deleted is greater than the current node's key, move to the right subtree.
If the key matches the current node's key, proceed to delete this node.
  
Delete the Node:
Node with no child (leaf node): Simply delete the node and return NULL.
Node with one child: Copy the child node's content to the current node and delete the child.
Node with two children: Find the inorder successor (the smallest node in the right subtree), copy its key to the current node, and delete the inorder successor.
  
Update Height:
After deletion, update the height of the current node.
The height of a node is 1 plus the maximum height of its left and right subtrees.
  
Check Balance:
Calculate the balance factor of the current node:
Balance factor = height of left subtree - height of right subtree.
If the balance factor is more than 1 or less than -1, the node has become unbalanced and requires rotations.

Perform Rotation (if unbalanced):
If the node is unbalanced, there are 4 possible cases:
Left-Left (LL) Case: If the left subtree of the left child is taller, perform a right rotation.
Right-Right (RR) Case: If the right subtree of the right child is taller, perform a left rotation.
Left-Right (LR) Case: If the right subtree of the left child is taller, perform a left rotation on the left child, then a right rotation on the current node.
Right-Left (RL) Case: If the left subtree of the right child is taller, perform a right rotation on the right child, then a left rotation on the current node.
  
Return the modified node:
After performing rotations (if needed), return the (potentially modified) node as the root of the subtree.

Preorder Traversal Algorithm:
Start with the root node:
If the node is not NULL, print the key.
Recursively traverse the left subtree.
Recursively traverse the right subtree.
Continue the traversal:

Visit the left child first, then the right child. The root node is processed before its children, making it a preorder traversal.
  
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
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
    x->height = 1 + (height(x->left),
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
    return height(N->left) - 
           height(N->right);
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
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
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
Node * minValueNode(Node* node) {
    Node* current = node;

    // loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || 
            (root->right == nullptr)) {
            Node *temp = root->left ? 
                         root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; 
            free(temp);
        } else {
            
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == nullptr)
        return root;
    root->height = 1 + max(height(root->left), 
                   height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && 
        getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && 
        getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && 
        getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && 
        getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after"
            " deletion of 10 \n";
    preOrder(root);

    return 0;
}
