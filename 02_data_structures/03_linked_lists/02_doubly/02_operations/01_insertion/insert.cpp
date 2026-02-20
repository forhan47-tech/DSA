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
    int count; 
public:
    Doubly() {
        head = tail = nullptr;
        count = 0;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    int size() {
        return count;
    }

    void insert(int val, int pos) {
        if(pos < 0 || pos > size()) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (pos == 0) {
            push_front(val);
            return;
        }

        if(pos == size()) {
            push_back(val);
            return;
        }

        Node* curr = head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
        count++;
    }
};

int main() {
    Doubly dl;
    dl.insert(10, 0);
    dl.insert(20, 1);
    dl.insert(30, 2);
    dl.insert(15, 1);
    cout << "Insertion at position completed!" << endl;
    return 0;
}
