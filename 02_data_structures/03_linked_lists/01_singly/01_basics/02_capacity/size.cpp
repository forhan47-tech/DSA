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

    int size() {
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
};

int main() {
    Singly sl;
    cout << "Size of the list: " << sl.size() << endl;
    return 0;
}
