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

    Node* findMax(Node* root) {
        if (!root) 
            return nullptr;

        while (root->right) 
            root = root->right;
        return root;
    }

public:
    BST() {
        root = nullptr;
    }

    int findMax() {
        Node* maxNode = findMax(root); 
        if (!maxNode) 
            throw runtime_error("Tree is empty!");
        return maxNode->data;
    }
};

int main() {
    BST bst;
}