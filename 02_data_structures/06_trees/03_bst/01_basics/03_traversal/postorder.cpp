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

    void postorder(Node* root) {
        if (root == nullptr) 
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

public:
    BST() {
        root = nullptr;
    }

    void dfs() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    bst.dfs();
}
