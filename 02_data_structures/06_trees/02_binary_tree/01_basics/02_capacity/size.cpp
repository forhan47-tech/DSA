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

    int findSize(Node* root) { 
        if (!root) 
            return 0; 
        return 1 + findSize(root->left) + findSize(root->right); 
    }


public:
    BinaryTree() {
        root = nullptr;
    }

    int size() { 
        return findSize(root); 
    }
};

int main() {
    BinaryTree bt;
}
