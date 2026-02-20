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

    void traverse() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    Circular cl;
    cl.traverse();
    return 0;
}
