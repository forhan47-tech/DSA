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
};

int main() {
    SimpleQueue sq;
}
