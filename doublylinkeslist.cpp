Write a program to implement a Doubly Linked List. The program should perform the following operations:

Create a doubly linked list and insert elements at the beginning and at the end.
Delete an element from the list.
Traverse the list in both forward and backward directions.
Display the list.

Doubly Linked List Algorithm
A Doubly Linked List is a linked list in which each node contains three fields:

A data field to store the value.
A next pointer to point to the next node.
A prev pointer to point to the previous node.
Basic Operations:

Insertion at the Beginning:

Create a new node.
Set the next of the new node to the current head of the list.
Set the prev of the current head to the new node.
Update the head pointer to the new node.
Insertion at the End:

Traverse to the last node of the list.
Create a new node and set its prev pointer to the last node.
Set the next pointer of the last node to the new node.
Update the tail pointer if necessary.
Deletion:

Locate the node to be deleted.
Update the next pointer of the previous node (if exists) to point to the next node.
Update the prev pointer of the next node (if exists) to point to the previous node.
Delete the node.
Traversal:

Forward Traversal: Start from the head and move towards the tail using the next pointer.
Backward Traversal: Start from the tail and move towards the head using the prev pointer.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete a node
    void deleteNode(int val) {
        if (head == nullptr) return;  // List is empty

        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Element not found!" << endl;
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail != nullptr) tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Forward traversal
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Backward traversal
    void displayBackward() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);

    cout << "List after insertion:" << endl;
    list.displayForward();  

    cout << "List in reverse order:" << endl;
    list.displayBackward();  
  
    list.deleteNode(20);
    cout << "List after deleting 20:" << endl;
    list.displayForward();

    return 0;
}
