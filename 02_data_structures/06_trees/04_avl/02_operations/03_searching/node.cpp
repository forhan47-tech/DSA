#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
    Node* root;

    bool searchHelper(Node* node, int key) {
    if (!node) return false;
    if (node->data == key) return true;
    if (key < node->data) return searchHelper(node->left, key);
    else return searchHelper(node->right, key);
}

public:
    AVL() {
        root = nullptr;
    }

    bool search(int key) {
    return searchHelper(root, key);
    }
};

int main() {
    AVL tree;
}
