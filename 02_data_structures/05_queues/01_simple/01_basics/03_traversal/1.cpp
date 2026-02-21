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

    bool empty() { 
        return front > rear; 
    }

    void display() { 
        if (empty()) { 
            cout << "Queue is empty!\n"; 
            return; 
        } 

        cout << "Queue elements: "; 
        for (int i = front; i <= rear; i++) { 
            cout << arr[i] << " "; 
        } 
        cout << endl; 
    }
};

int main() {
    SimpleQueue q(5);
}
