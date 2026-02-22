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

    int search(int key) {
        Node* curr = head;
        int pos = 0;
        
        while (curr != nullptr) {
            if (curr->data == key) {
                return pos;
            }
            curr = curr->next;
            pos++;
        }
        return -1; 
    }

    bool contains(int key) {
        return search(key) != -1;
    }
};

int main() {
    Singly sl;
    cout << "Position of 10: " << sl.search(10) << endl;
    cout << "Does the list contain 20? " << (sl.contains(20) ? "Yes" : "No") << endl;
    return 0;  
}