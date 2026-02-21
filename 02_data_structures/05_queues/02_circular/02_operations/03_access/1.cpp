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

    int peek() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    CircularQueue cq(5);
}
