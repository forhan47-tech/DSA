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

    int sizeHelper(Node* root) {
    if (!root) 
        return 0;
    
    return 1 + sizeHelper(root->left) + sizeHelper(root->right);
    }


public:
    AVL() {
        root = nullptr;
    }

    int size() { 
        return sizeHelper(root); 
    }
};
int main() {
    AVL tree;
}
