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

    ~Doubly() {
        clear();
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = tail = nullptr;
        count = 0;
    }
};

int main() {
    Doubly dl;
    dl.clear();
    cout << "Cleared the list!" << endl;
    return 0;
}