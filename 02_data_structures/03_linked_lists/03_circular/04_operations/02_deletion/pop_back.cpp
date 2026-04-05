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
    
    void pop_back() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if(head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* curr = head;
            while (curr->next != tail) {
                curr = curr->next;
            }
            curr->next = head;
            delete tail;
            tail = curr;
        }
    }
};

int main() {
    Circular cl;
    cl.pop_back();
    cout << "Popped back element!" << endl;
    return 0;
}
