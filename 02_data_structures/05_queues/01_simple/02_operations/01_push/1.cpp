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

    bool full() { 
        return rear == capacity-1; 
    }

    void enqueue(int val) { 
        if (full()) { 
            cout << "Queue Overflow\n"; 
            return; 
        } 

        arr[++rear] = val; 
    }
};

int main() {
    SimpleQueue q(5);
}
