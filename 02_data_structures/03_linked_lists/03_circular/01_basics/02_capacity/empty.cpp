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
    
    bool empty() {
        return head == nullptr;
    }
};

int main() {
    Circular cl;
    cout << "Is the circular list empty? " << (cl.empty() ? "Yes" : "No") << endl;
    return 0;
}
