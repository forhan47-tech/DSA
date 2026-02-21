#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
    Node* root;

    void postorder(Node* node) {
        if (node == nullptr) 
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() {
        root = nullptr;
    }

    void traverse() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
}