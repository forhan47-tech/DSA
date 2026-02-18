#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Doubly {
    Node* head;
    Node* tail;
public:
    Doubly() {
        head = tail = nullptr;
    }

    int search(int val) {
        Node* curr = head;
        int pos = 0;
        while (curr != nullptr) {
            if (curr->data == val) {
                return pos;
            }
            curr = curr->next;
            pos++;
        }
        return -1;
    }

    bool contains(int val) {
        return search(val) != -1;
    }
};

int main() {
    Doubly dl;
    cout << "Position of 10: " << dl.search(10) << endl;
    cout << "Does the list contain 20? " << dl.contains(20) << endl;
    return 0;
}
