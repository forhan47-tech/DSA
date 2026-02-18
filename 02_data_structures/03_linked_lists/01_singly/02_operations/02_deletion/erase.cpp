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

    void pop_front() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void erase(int pos) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if (pos == 0) {
            pop_front();
            return;
        }

        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr || curr->next == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* temp = curr->next;
        curr->next = temp->next;

        if(temp == tail) {
            tail = curr;
        }

        delete temp;
    }   
};

int main() {
    Singly fl;
    fl.erase(0);
    return 0;  
}
