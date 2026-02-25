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

    bool searchDFS(Node* node, int key) {
        if (!node) 
            return false;

        if (node->data == key) 
            return true;

        return searchDFS(node->left, key) || searchDFS(node->right, key);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    bool search(int key) { 
        return searchDFS(root, key); 
    }
};

int main() {
    BinaryTree bt;
}