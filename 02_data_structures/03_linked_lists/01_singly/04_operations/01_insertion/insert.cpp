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
    int count;
public:
    Singly() {
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
        } else {
            newNode->next = head;
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
            tail = newNode;
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
    Singly sl;
    sl.insert(10, 0); 
    sl.insert(20, 1);
    sl.insert(15, 1); 
    return 0;
}
