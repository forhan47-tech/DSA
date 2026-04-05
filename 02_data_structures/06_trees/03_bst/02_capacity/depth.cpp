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

    int depthHelper(Node* root, int key, int depth) {
        if (!root) return -1;

        if (root->data == key) return depth;

        if (key < root->data) 
            return depthHelper(root->left, key, depth + 1);
        else 
            return depthHelper(root->right, key, depth + 1);
    }

public:
    BST() {
        root = nullptr;
    }

    int depth(int key) {
        return depthHelper(root, key, 0);
    }
};

int main() {
    BST bst;
}
