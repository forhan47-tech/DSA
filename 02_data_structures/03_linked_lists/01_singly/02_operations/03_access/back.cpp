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

    int back() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        return tail->data;
    }
};

int main() {
    Singly fl;
    cout << "Back element: " << fl.back() << endl;
    return 0;  
}