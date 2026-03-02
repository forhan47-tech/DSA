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

    bool search(Node* root, int val) {
        if (root == nullptr) 
            return false;

        if (root->data == val) 
            return true;

        if (val < root->data) 
            return search(root->left, val);
        else 
            return search(root->right, val);
    }

public:
    BST() {
        root = nullptr;
    }

    bool find(int val) {
        return search(root, val);
    }
};

int main() {
    BST bst;
}
