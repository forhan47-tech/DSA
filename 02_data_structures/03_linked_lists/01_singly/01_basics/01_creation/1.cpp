#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {
    Node* head = new Node(10);
    cout << "Data: " << head->data << endl;
    cout << "Next: " << head->next << endl;
    return 0;
}
