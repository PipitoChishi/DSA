#include <iostream>

class Queue {
private:
    int front, rear, capacity;
    int* queue;

public:
    Queue(int c) {
        front = 0;
        rear = -1;
        capacity = c;
        queue = new int[c];
    }

    ~Queue() { delete[] queue; }

    void enqueue(int data) {
         
        if (rear == capacity - 1) {
            std::cout << "Queue is full" << std::endl;
            return;
        }

        queue[++rear] = data;
    }

    void dequeue() {
         
        if (front > rear) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        for (int i = 0; i < rear; i++) {
            queue[i] = queue[i + 1];
        }

        rear--;
    }

    void display() {
        if (front > rear) {
            std::cout << "Queue is Empty" << std::endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            std::cout << queue[i] << " <-- ";
        }
        std::cout << std::endl;
    }

    void frontElement() {
        if (rear == -1) {
            std::cout << "Queue is Empty" << std::endl;
            return;
        }
        std::cout << "Front Element is: " << queue[front] << std::endl;
    }
};

int main() {
     
    Queue q(4);

    q.display();

    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.enqueue(60);

    q.display();

    q.dequeue();
    q.dequeue();

    std::cout << "After two node deletions" << std::endl;
     
    q.display();

    std::cout << "After one insertion" << std::endl;
    q.enqueue(60);

    q.display();

    q.frontElement();

    return 0;
}