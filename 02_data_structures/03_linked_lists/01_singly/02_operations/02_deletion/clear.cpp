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
    int count;
public:
    Singly() {
        head = tail = nullptr;
        count = 0;
    }

    ~Singly() {
        clear();
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = tail = nullptr;
        count = 0;
    }
};

int main() {
    Singly fl;
    fl.clear();
    cout << "List cleared!" << endl;
    return 0;  
}
