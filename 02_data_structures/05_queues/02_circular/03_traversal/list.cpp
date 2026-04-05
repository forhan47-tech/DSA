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

    void display() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* curr = front;
        cout << "Queue elements: ";
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != front);
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
}
