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

    int depthHelper(Node* root, int key, int level) {
        if (!root) return -1;

        if (root->data == key) return level;

        int leftDepth = depthHelper(root->left, key, level + 1);
        if (leftDepth != -1) return leftDepth;

        return depthHelper(root->right, key, level + 1);
    }

public:
    AVL() {
        root = nullptr;
    }

    int depth(int key) {
        return depthHelper(root, key, 0);
    }
};

int main() {
    AVL avl;
}
