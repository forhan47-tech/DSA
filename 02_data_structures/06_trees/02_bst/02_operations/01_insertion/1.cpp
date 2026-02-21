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

    Node* insert(Node* node, int val) {
        if (node == nullptr) 
            return new Node(val);

        if (val < node->data) 
            node->left = insert(node->left, val);
        else if (val > node->data) 
            node->right = insert(node->right, val);
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
}
