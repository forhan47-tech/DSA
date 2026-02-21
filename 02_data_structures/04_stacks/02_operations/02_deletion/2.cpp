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

    bool empty() {
        return top == nullptr;
    }

    void pop() { 
        if (empty()) { 
            cout << "Stack Underflow\n"; 
            return; 
        } 

        Node* temp = top; 
        top = top->next; 
        delete temp; 
    }
};

int main() {
    Stack st;
}
