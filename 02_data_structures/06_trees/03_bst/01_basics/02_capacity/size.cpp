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

    int findSize(Node* root) {
        if (root == nullptr) 
            return 0;
        
        return 1 + findSize(root->left) + findSize(root->right);
    }

public:
    BST() {
        root = nullptr;
    }

    int size() {
        return findSize(root);
    }
};

int main() {
    BST bst;
    cout << "Tree size: " << bst.size() << endl;
}
