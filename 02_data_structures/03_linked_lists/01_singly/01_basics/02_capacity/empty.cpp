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

    bool empty() {
        return head == nullptr;
    }
};

int main() {
    Singly fl;
    cout << "Is the list empty? " << fl.empty() << endl;
    return 0;  
}
