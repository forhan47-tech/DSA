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

    void pop_front() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

       if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        count--;
    }

    void pop_back() {
        if(tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if(head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        count--;
    }

    void remove(int val) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == val) {
                Node* temp = curr;
                curr = curr->next;

                if (temp == head) {
                    pop_front();
                } else if (temp == tail) {
                    pop_back();
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    count--;
                }
            } else {
                curr = curr->next;
            }
        }
    }
};

int main() {
    Doubly dl;
    dl.remove(10);
    cout << "Removed element with value 10!" << endl;
    return 0;
}