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

    int size() {
        if (empty()) return 0;
        int count = 0;
        Node* curr = front;
        do {
            count++;
            curr = curr->next;
        } while (curr != front);
        return count;
    }
};

int main() {
    CircularQueue cq;
}
