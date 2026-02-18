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
        
    }
};

int main() {
    Singly fl;
    fl.reverse();
    cout << "List reversed!" << endl;
    return 0;  
}