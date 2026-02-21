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
};

int main() {
    CircularQueue cq(5);
}
