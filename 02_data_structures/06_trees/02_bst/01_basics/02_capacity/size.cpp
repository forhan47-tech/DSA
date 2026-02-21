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

    int size(Node* node) {
        if (node == nullptr) 
            return 0;
        return 1 + size(node->left) + size(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    int size() {
        return size(root);
    }
};

int main() {
    BST tree;
    cout << "Tree size: " << tree.size() << endl;
}
