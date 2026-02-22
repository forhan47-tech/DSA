#include <iostream>
using namespace std;

class SimpleQueue {
    int *arr;
    int front, rear, cap;

public:
    SimpleQueue(int size) {
        cap = size;
        arr = new int[cap];
        front = 0;
        rear = -1;
    }

    ~SimpleQueue() {
        delete[] arr;
    }
};

int main() {
    SimpleQueue sq(5);
}
