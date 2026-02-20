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
public:
    Circular() {
        head = tail = nullptr;
    }  
    
    int search(int key) {
        if (head == nullptr) {
            return -1;
        }

        Node* curr = head;
        int pos = 0;
        do {
            if (curr->data == key) {
                return pos;
            }
            curr = curr->next;
            pos++;
        } while (curr != head);
        
        return -1;
    }

    bool contains(int key) {
        return search(key) != -1;
    }
};

int main() {
    Circular cl;
        cout << "Position of 10: " << cl.search(10) << endl;
        cout << "Does the list contain 20? " << (cl.contains(20) ? "Yes" : "No") << endl;
    return 0;
}