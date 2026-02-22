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

    bool full() {
        return (rear+1) % cap == front;
    }
};

int main() {
    CircularQueue cq(5);
}
