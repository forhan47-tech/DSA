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

    void freeTree(Node* curr) { 
        if (!curr) 
            return; 

        freeTree(curr->left); 
        freeTree(curr->right); 
        delete curr; 
    }

public:
    AVL() {
        root = nullptr;
    }

    ~AVL() {
        freeTree(root); 
    }
};

int main() {
    AVL avl;
}
