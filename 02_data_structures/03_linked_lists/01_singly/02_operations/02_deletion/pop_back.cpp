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
    
public:
    Singly() {
        head = tail = nullptr;
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if(head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        
        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        
        delete tail;
        tail = curr;
        tail->next = nullptr;
    }
};

int main() {
    Singly fl;
    fl.pop_back();
    cout << "Popped back element!" << endl;
    return 0;
}
