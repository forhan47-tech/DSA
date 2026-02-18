#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Doubly {
    Node* head;
    Node* tail;
public:
    Doubly() {
        head = tail = nullptr;
    }

    int front() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        return head->data;
    }
};

int main() {
    Doubly dl;
    cout << "Front element: " << dl.front() << endl;
    return 0;
}
