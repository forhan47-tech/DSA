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

    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void dfs() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
}
