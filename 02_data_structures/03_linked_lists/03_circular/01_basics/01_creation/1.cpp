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
};

int main() {
    Circular cl;
    cout << "Circular Linked List created successfully!" << endl;
    return 0;
}
