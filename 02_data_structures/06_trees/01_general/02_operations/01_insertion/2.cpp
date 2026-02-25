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

// Recursive helper to delete a subtree
void deleteHelper(Node* node) {
    if (!node) return;
    for (Node* c : node->children) {
        deleteHelper(c);
    }
    delete node;
}

// Delete a specific child subtree from parent
void deleteSubtree(Node* parent, int target) {
    for (auto it = parent->children.begin(); it != parent->children.end(); ++it) {
        if ((*it)->data == target) {
            deleteHelper(*it);               // delete target subtree
            parent->children.erase(it);      // remove from parent's list
            return;
        } else {
            deleteSubtree(*it, target);      // recursive search in children
        }
    }
}

// Preorder traversal to verify
void preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    for (Node* c : node->children) preorder(c);
}
