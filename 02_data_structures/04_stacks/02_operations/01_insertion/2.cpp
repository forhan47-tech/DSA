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

class Stack {
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int val) { 
        Node* newNode = new Node(val); 
        newNode->next = top; 
        top = newNode; 
    }
};

int main() {
    Stack st;
}
