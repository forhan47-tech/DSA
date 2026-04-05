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

    void display() { 
        if (empty()) { 
            cout << "Stack is empty!\n"; 
            return; 
        } 
        
        cout << "Stack elements (top to bottom): "; 
        Node* curr = top; 
        while (curr != nullptr) { 
            cout << curr->data << " "; 
            curr = curr->next; 
        } 
        cout << endl; 
    }
};

int main() {
    Stack st;
}
