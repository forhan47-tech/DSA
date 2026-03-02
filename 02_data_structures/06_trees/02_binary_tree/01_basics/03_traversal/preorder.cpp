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

    void preorder(Node* root) {
        if (!root) 
            return;
        
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void dfs() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
}
