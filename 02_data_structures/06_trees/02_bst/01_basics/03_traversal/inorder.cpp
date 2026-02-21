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

    void inorder(Node* node) {
        if (node == nullptr) 
            return;
        
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void traverse() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.traverse();
}
