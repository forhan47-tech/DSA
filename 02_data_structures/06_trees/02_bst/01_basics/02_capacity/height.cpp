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

    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

public:
    BST() {
        root = nullptr;
    }

    int height() {
        return height(root);
    }
};

int main() {
    BST tree;
    cout << "Tree height: " << tree.height() << endl;
}
