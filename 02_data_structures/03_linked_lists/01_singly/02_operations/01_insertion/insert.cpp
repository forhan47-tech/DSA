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
    
    void insert(int val, int pos) {
        if (pos == 0) {
            push_front(val);
            return;
        }
        
        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
};

int main() {
    Singly fl;
    fl.insert(10, 0);
    fl.insert(20, 1);
    fl.insert(30, 1);
    fl.insert(40, 3);
    fl.insert(50, 10); // Out of bounds
    cout << "Insertion completed!" << endl;
    return 0;
}
