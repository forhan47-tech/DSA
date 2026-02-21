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

    int peek() { 
        if (empty()) { 
            cout << "Queue is empty!\n"; 
            return -1; 
        } 
        return front->data; 
    }
};

int main() {
    SimpleQueue sq;
}
