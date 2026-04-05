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
    SimpleQueue sq(5);
}
