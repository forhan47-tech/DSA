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

    void remove(int val) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* curr = head;
        Node* prev = tail;
        
        do {
            if (curr->data == val) {
                if (curr == head) {
                    pop_front();
                    curr = head;
                } else if (curr == tail) {
                    pop_back();
                    curr = head;
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
        } while (curr != head);
    }
};

int main() {
    Circular cl;
    cl.remove(10);
    return 0;
}
