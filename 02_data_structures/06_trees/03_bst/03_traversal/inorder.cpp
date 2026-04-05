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

    void inorder(Node* root) {
        if (root == nullptr) return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void dfs() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
}
