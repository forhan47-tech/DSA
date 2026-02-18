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
    Singly fl;
    cout << "Position of 10: " << fl.search(10) << endl;
    cout << "Does the list contain 20? " << fl.contains(20) << endl;
    return 0;  
}