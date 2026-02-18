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

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

int main() {
    Singly fl;
    fl.push_back(10);
    fl.push_back(20);
    fl.push_back(30);
    fl.push_back(40);   
    fl.push_back(50);
    cout << "Insertion at back completed!" << endl;
    return 0;
}
