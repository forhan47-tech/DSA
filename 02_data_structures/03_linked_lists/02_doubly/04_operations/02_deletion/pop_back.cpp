#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Doubly {
    Node* head;
    Node* tail;
public:
    Doubly() {
        head = tail = nullptr;
    }

    void pop_back() {
        if(tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if(head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }
};

int main() {
    Doubly dl;
    dl.pop_back();
    cout << "Popped back element!" << endl;
    return 0;
}
