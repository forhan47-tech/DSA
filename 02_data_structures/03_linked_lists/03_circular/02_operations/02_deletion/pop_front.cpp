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

    void pop_front() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if(head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }
};

int main() {
    Circular cl;
    cl.pop_front();
    cout << "Popped front element!" << endl;
    return 0;
}
