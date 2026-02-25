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

    void freeTree(Node* root) { 
        if (!root) 
            return; 

        freeTree(root->left); 
        freeTree(root->right); 
        delete root; 
    }

public:
    AVL() {
        root = nullptr;
    }
};

int main() {
    AVL avl;
}