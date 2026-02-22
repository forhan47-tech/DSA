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
};

int main() {
    CircularQueue cq(5);
}
