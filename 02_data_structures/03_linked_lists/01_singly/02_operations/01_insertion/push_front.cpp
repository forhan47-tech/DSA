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

    void push_front(int val) {
        Node* newNode = new Node(val);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
};

int main() {
    Singly sl;
    sl.push_front(10);
    sl.push_front(20);  
    sl.push_front(30);
    sl.push_front(40);
    cout << "Insertion at front completed!" << endl;
    return 0;
}
