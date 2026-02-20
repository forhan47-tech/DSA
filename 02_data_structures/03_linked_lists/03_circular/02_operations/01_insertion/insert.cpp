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

class Circular {
    Node* head;
    Node* tail;
    int count;
public:
    Circular() {
        head = tail = nullptr;
        count = 0;
    }

    int size() {
        return count;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        count++;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        count++;
    }
    
    void insert(int val, int pos) {
        if (pos < 0 || pos > size()) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (pos == 0) {
            push_front(val);
            return;
        }

        if (pos == size()) {
            push_back(val);
            return;
        }

        Node* curr = head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        count++;
    }
};

int main() {
    Circular cl;
    cl.insert(10, 0);
    cl.insert(20, 1);
    cl.insert(30, 2);
    cl.insert(15, 1);
    cout << "Insertion at specific positions in circular list completed!" << endl;
    return 0;
}
