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
    }
};

int main() {
    Singly sl;
    sl.pop_back();
    cout << "Popped back element!" << endl;
    return 0;
}
