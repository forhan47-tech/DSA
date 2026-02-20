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

public:
    Circular() {
        head = tail = nullptr;
    }  
    
    void clear() {
        if (head == nullptr) {
            cout << "List is already empty!" << endl;
            return;
        }

        Node* curr = head;
        do {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        } while (curr != head);
        head = tail = nullptr;
    }
};

int main() {
    Circular cl;
    cl.clear();
    cout << "Cleared the circular list!" << endl;
    return 0;
}
