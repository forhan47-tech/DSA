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

    bool empty() {
        return head == nullptr;
    }
};

int main() {
    Doubly dl;
    cout << "Is the list empty? " << dl.empty() << endl;
    return 0;
}
