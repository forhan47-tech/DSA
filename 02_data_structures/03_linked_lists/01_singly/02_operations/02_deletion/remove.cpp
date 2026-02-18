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

    void remove(int val) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        while (head != nullptr && head->data == val) {
            pop_front();
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != val) {
            curr = curr->next;  
        }

        if (curr->next == nullptr) {
            cout << "Value not found in the list" << endl;
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
    fl.remove(10);
    return 0;  
}
