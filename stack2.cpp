Write a program to implement a stack using dynamic memory allocation. The program should include the following operations:

Push(x): Insert an element x onto the stack.
Pop(): Remove the top element from the stack.
Top(): Return the top element of the stack without removing it.
Check for overflow and underflow: Ensure proper error handling when the stack is full or empty.

Algorithm:
Create the Stack Class:

Define a class stack with a pointer arr to hold the stack elements and an integer top to track the top element.
In the constructor, initialize arr to dynamically allocate an array of size n and set top = -1, indicating the stack is empty.
Push Operation:

Check if the stack is full (top == n-1).
If the stack is not full, increment top and insert the element at arr[top].
Pop Operation:

Check if the stack is empty (top == -1).
If the stack is not empty, decrement top, effectively removing the top element.
Top Operation:

Return the element at arr[top] if the stack is not empty.
Handle Stack Overflow and Underflow:

Print appropriate messages when attempting to perform operations on a full or empty stack.

#include <iostream>
using namespace std;

#define n 100

class stack {
    int *arr;
    int top;

public:
    stack() {
        arr = new int[n];
        top = -1;
    }
    void push(int x) {
        if (top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    // Pop function to remove the top element from the stack
    void pop() {
        if (top == -1) {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    // Function to return the top element of the stack
    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;  
        }
        return arr[top];
    }
};

int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl; 

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;  

    s.pop();
    s.pop();
    s.pop();  

    return 0;
}
