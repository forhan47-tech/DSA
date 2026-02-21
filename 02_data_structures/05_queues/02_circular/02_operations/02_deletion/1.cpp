#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool empty() {
        return rear == -1;
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }
};

int main() {
    CircularQueue cq(5);
}
