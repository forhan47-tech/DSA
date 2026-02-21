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

class SimpleQueue {
    Node* front;
    Node* rear;

public:
    SimpleQueue() {
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

        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
              Node* temp = front;
              front = front->next;
              delete temp;
        }
    }
};

int main() {
    SimpleQueue sq;
}
