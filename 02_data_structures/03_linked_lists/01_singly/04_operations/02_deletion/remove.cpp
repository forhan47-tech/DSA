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

    void pop_front() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        count--;
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* curr = head;
            while (curr->next != tail) {
                curr = curr->next;
            }
            curr->next = nullptr;
            delete tail;
            tail = curr;
        }
        count--;
    }

    void remove(int val) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->data == val) {
                if (curr == head) {
                    pop_front();
                    curr = head;
                } else if (curr == tail) {
                    pop_back();
                    curr = nullptr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                    count--;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
};

int main() {
    Singly fl;
    fl.remove(10);
    return 0;  
}
