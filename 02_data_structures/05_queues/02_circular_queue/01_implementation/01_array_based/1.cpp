#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, count, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
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

    bool full() {
        return count == capacity;
    }

    int size() {
        return count;
    }

    void enqueue(int val) {
        if (full()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    int peek() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1; // sentinel value
        }
        return arr[front];
    }

    void traverse() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cq.traverse(); // 10 20 30 40

    cout << "Front element: " << cq.peek() << endl; // 10

    cq.dequeue();
    cq.traverse(); // 20 30 40

    cq.enqueue(50);
    cq.enqueue(60);
    cq.traverse(); // 20 30 40 50 60

    cq.enqueue(70); // Queue is full!
}
