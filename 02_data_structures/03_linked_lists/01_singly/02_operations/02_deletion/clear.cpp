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

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            delete temp;
        }
        head = tail = nullptr;
    }
};

int main() {
    Singly fl;
    fl.clear();
    cout << "List cleared!" << endl;
    return 0;  
}
