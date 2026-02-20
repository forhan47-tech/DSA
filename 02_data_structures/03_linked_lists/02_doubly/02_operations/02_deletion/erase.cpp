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

    int size() {
        return count;
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

    void erase(int pos) {
        if (pos < 0 || pos >= size()) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (pos == 0) {
            pop_front();
            return;
        }

        if (pos == size() - 1) {
            pop_back();
            return;
        }

        Node* curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        count--;
    }
};

int main() {
    Doubly dl;
    dl.erase(0);
    cout << "Erased element at position 0!" << endl;
    return 0;
}
