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

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }
    
    void display() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size(); i++) {
            int idx = (front + i) % cap;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);
}
