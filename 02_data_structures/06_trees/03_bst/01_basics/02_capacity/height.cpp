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

    int findHeight(Node* root) {
        if (root == nullptr) 
            return 0;
        
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }

public:
    BST() {
        root = nullptr;
    }

    int height() {
        return findHeight(root);
    }
};

int main() {
    BST bst;
    cout << "Tree height: " << bst.height() << endl;
}
