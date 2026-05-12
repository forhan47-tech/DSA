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

    Node* findLCA(Node* root, int a, int b) {
        if (!root) 
            return nullptr;

        if (a < root->data && b < root->data) 
            return findLCA(root->left, a, b);

        if (a > root->data && b > root->data) 
            return findLCA(root->right, a, b);

        return root;
    }

public:
    BST() {
        root = nullptr;
    }

    int LCA(int a, int b) {
        Node* lca = findLCA(root, a, b);
        if (!lca) 
            return -1; 
        return lca->data;
    }
};

int main() {
    BST bst;
}
