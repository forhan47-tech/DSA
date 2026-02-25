#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;
    Node(int val) { data = val; }
};

// Insert function
Node* insert(Node* parent, int val) {
    Node* child = new Node(val);
    parent->children.push_back(child);
    return child;
}

// Preorder traversal to verify insertion
void preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    for (Node* c : node->children) preorder(c);
}

int main() {
    Node* root = new Node(1);

    Node* child2 = insert(root, 2);
    Node* child3 = insert(root, 3);
    Node* child4 = insert(root, 4);

    insert(child3, 5);
    insert(child3, 6);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}
