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

    Node* LCA(Node* root, int a, int b) {
        if (!root) 
            return nullptr;

        if (a < root->data && b < root->data) 
            return LCA(root->left, a, b);

        if (a > root->data && b > root->data) 
            return LCA(root->right, a, b);

        return root;
    }

public:
    BST() {
        root = nullptr;
    }

    int LCA(int a, int b) {
        Node* lca = LCA(root, a, b);
        if (!lca) 
            throw runtime_error("LCA not found!");
        return lca->data;
    }
};

int main() {
    BST bst;
}
