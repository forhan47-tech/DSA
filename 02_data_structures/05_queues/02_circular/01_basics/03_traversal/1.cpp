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

    void display() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % cap;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);
}
