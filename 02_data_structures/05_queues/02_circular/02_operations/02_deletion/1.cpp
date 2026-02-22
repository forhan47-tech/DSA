#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, cap;

public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
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
            front = (front + 1) % cap;
        }
    }
};

int main() {
    CircularQueue cq(5);
}
