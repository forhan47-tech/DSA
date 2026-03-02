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

class BinaryTree {
    Node* root;

    int depthHelper(Node* root, int key, int level) {
        if (!root) 
            return -1;

        if (root->data == key) 
            return level;

        int leftDepth = depthHelper(root->left, key, level + 1);
        if (leftDepth != -1) return leftDepth;

        return depthHelper(root->right, key, level + 1);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    int depth(int key) { 
        return depthHelper(root, key, 0); 
    }
};

int main() {
    BinaryTree bt;
}
