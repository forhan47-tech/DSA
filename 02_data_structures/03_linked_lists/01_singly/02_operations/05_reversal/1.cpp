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

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next; 
            curr->next = prev; 
            prev = curr;       
            curr = next;       
        }

        swap(head, tail);
    }
};

int main() {
    Singly sl;
    sl.reverse();
    cout << "List reversed!" << endl;
    return 0;  
}