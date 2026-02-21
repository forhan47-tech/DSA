#include <iostream>
using namespace std;

class SimpleQueue {
    int *arr;
    int front, rear, capacity;

public:
    SimpleQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~SimpleQueue() {
        delete[] arr;
    }

    bool empty() { 
        return front > rear; 
    }

    void dequeue() { 
        if (empty()) { 
            cout << "Queue Underflow\n"; 
            return; 
        }
        front++; 
    }
};

int main() {
    SimpleQueue q(5);
}
