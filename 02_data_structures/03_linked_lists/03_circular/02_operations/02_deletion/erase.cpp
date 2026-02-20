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
    int count;
public:
    Circular() {
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

        if(head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        count--;
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
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
            curr->next = head;
            delete tail;
            tail = curr;
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
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        count--;
    }
};

int main() {
    Circular cl;
    cl.erase(0);
    cout << "Erased element at position 0!" << endl;
    return 0;
}
