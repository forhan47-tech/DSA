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

    void postorder(Node* root) {
        if (!root) return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void dfs() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
}
