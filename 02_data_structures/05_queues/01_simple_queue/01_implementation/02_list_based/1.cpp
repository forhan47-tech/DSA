#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
    Node* head;  // front
    Node* tail;  // rear
    int count;

public:
    Queue() {
        head = tail = nullptr;
        count = 0;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr; // queue became empty
        delete temp;
        count--;
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1; // sentinel value
        }
        return head->data;
    }

    void clear() {
        while (!empty()) {
            dequeue();
        }
    }

    ~Queue() {
        clear();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Size: " << q.size() << endl;          // 3

    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl; // 20

    q.clear();
    cout << "Size after clear: " << q.size() << endl; // 0
}
