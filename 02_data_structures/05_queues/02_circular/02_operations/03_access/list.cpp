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

    int peek() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    CircularQueue cq;
    cout << "Front: " << cq.peek() << endl;
}
