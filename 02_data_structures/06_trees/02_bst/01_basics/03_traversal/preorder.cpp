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

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void traverse() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
}
