#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, cap, count;

public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool full() {
        return count == cap;
    }
};

int main() {
    CircularQueue cq(5);
}
