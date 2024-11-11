Write a program to implement a stack using an array. The program should support the following operations:

Push: Add an element to the stack.
Pop: Remove and return the top element from the stack.
isEmpty: Check if the stack is empty.
isFull: Check if the stack is full.

Algorithm:
Initialize the Stack:

Create a structure Stack with an array to hold the stack elements and an integer top to point to the top element in the stack.
Set top = -1 to indicate the stack is empty initially.
Push Operation:

Check if the stack is full (top == MAX_SIZE - 1).
If not, increment top and insert the new value at arr[top].
Pop Operation:

Check if the stack is empty (top == -1).
If not, return the value at arr[top] and decrement top.
isEmpty Operation:

Return true if top == -1, indicating the stack is empty.
isFull Operation:

Return true if top == MAX_SIZE - 1, indicating the stack is full.

#include<iostream>
#define MAX_SIZE 100
using namespace std;

// Stack structure definition
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push a value onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        cout << "Stack Overflow!" << endl;
    } else {
        stack->arr[++stack->top] = value;
    }
}

// Pop a value from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack Underflow!" << endl;
        return -1;
    } else {
        return stack->arr[stack->top--];
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    cout << "Popped: " << pop(&stack) << endl;   
    cout << "Popped: " << pop(&stack) << endl; 

    return 0;
}
