#include <iostream>
#include <algorithm>
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

    int heightHelper(Node* root) {
        if (!root) return 0;
        return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    int height() { 
        return heightHelper(root); 
    }
};

int main() {
    BinaryTree bt;
}
