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

    int peek() { 
        if (empty()) { 
            cout << "Queue is empty!\n"; 
            return -1; 
        } 
        return arr[front]; 
    }
};

int main() {
    SimpleQueue q(5);
}
