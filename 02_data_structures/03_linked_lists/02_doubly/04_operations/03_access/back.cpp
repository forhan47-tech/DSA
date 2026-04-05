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

    int back() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        return tail->data;
    }
};

int main() {
    Doubly dl;
    cout << "Back element: " << dl.back() << endl;
    return 0;
}
