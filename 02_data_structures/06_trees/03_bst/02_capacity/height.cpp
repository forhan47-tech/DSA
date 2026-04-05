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

    int heightHelper(Node* root) {
        if (root == nullptr) return 0;

        return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }

public:
    BST() {
        root = nullptr;
    }

    int height() {
        return heightHelper(root);
    }
};

int main() {
    BST bst;
    cout << "Tree height: " << bst.height() << endl;
}
