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

    int size() {
        if (head == nullptr) {
            return 0;
        }

        int count = 0;
        Node* curr = head;
        do {
            count++;
            curr = curr->next;
        } while (curr != head);
        return count;
    }
};

int main() {
    Circular cl;
    cout << "Size of circular list: " << cl.size() << endl;
    return 0;
}
