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

    int size() {
        int count = 0;
        Node* curr = top;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
};

int main() {
    Stack st;
}
