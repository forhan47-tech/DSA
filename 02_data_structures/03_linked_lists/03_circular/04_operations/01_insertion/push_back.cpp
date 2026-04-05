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

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
};

int main() {
    Circular cl;
    cl.push_back(10);
    cl.push_back(20);
    cl.push_back(30);
    cout << "Elements inserted at the back of the circular list!" << endl;
    return 0;
}
