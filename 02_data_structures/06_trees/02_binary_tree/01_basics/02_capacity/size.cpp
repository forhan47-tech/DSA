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

    int sizeHelper(Node* root) { 
        if (!root) 
            return 0; 
        return 1 + sizeHelper(root->left) + sizeHelper(root->right); 
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    int size() { 
        return sizeHelper(root); 
    }
};

int main() {
    BinaryTree bt;
}
