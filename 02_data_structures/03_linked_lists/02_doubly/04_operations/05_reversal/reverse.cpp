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

    void reverse() {
        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }

        tail = head;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
        }
    }
};

int main() {
    Doubly dl;
    dl.reverse();
    cout << "List reversed!" << endl;
    return 0;
}
