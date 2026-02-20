#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Circular {
    Node* head;
    Node* tail;

public:
    Circular() {
        head = tail = nullptr;
    }   

    int front() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return -1;
        }
        return head->data;
    }
};

int main() {
    Circular cl;
    cout << cl.front() << endl;
    return 0;
}
