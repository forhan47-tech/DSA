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

    void dequeue() {
        if (empty()) {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear) { // only one node
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; // maintain circular link
            delete temp;
        }
    }
};

int main() {
    CircularQueue cq;
    cq.dequeue();
}
