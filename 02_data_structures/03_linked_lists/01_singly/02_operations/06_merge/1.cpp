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

    void merge(Singly& other) {
        if (other.head == nullptr) {
            return; 
        }

        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        } else {
            tail->next = other.head;
            tail = other.tail;
        }

        other.head = other.tail = nullptr; 
    }
};

int main() {
    Singly fl1;
    Singly fl2;
    fl1.merge(fl2);
    cout << "Lists merged!" << endl;
    return 0;  
}