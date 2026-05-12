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

    int findHeight(Node* root) {
        if (!root) 
            return 0;

        return 1 + max(findHeight(root->left), findHeight(root->right));
    }

public:
    BST() {
        root = nullptr;
    }
    
    int balanceFactor() {
        if (!root) 
            return 0;

        return findHeight(root->left) - findHeight(root->right);
    }
};

int main() {
    BST bst;
}
