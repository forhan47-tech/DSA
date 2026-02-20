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

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head; 
            head = newNode;
            tail->next = head;
        }
    }
};

int main() {
    Circular cl;
    cl.push_front(10);
    cl.push_front(20);
    cl.push_front(30);
    cout << "Elements inserted at the front of the circular list!" << endl;
    return 0;
}
