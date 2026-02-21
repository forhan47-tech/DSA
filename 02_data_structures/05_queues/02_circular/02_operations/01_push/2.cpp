#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    bool empty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (empty()) {
            front = rear = newNode;
            rear->next = front; // circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // maintain circular link
        }
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
}
