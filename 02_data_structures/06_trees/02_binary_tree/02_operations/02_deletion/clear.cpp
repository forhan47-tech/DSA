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

    void freeTree(Node* root) {
        if (!root) 
            return;

        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }

public:
    BinaryTree() { 
        root = nullptr; 
    }

    ~BinaryTree() { 
        freeTree(root); 
    }
};

int main() {
    BinaryTree bt;
}
