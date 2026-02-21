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

    int peek() { 
        if (empty()) { 
            cout << "Stack is empty!\n"; 
            return -1; 
        } 

        return top->data; 
    }
};

int main() {
    Stack st;
}
