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

class Singly {
    Node* head;
    Node* tail;
public:
    Singly() {
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
    Singly sl;
    cout << "Front element: " << sl.front() << endl;
    return 0;  
}