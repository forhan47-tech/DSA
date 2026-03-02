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

    void preorder(Node* root) {
        if (root == nullptr) return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void dfs() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    bst.dfs();
}
