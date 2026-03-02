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

    int sizeHelper(Node* root) {
        if (root == nullptr) 
            return 0;
        
        return 1 + sizeHelper(root->left) + sizeHelper(root->right);
    }

public:
    BST() {
        root = nullptr;
    }

    int size() {
        return sizeHelper(root);
    }
};

int main() {
    BST bst;
    cout << "Tree size: " << bst.size() << endl;
}
