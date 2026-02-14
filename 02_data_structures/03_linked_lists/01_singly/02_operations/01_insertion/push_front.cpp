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

    void traverse() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
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
    Singly fl;
    fl.push_front(10);
    fl.push_front(20);  
    fl.push_front(30);
    fl.push_front(40);
    fl.traverse(); 
    return 0;
}
