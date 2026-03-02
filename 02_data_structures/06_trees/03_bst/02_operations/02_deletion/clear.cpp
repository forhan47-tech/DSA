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
    int count;


    void freeTree(Node* root) {
        if (root == nullptr) 
            return;

        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }

public:
    BST() {
        root = nullptr;
        count = 0;
    }

    ~BST() { 
        clear(); 
    }

    int size() const { 
        return count; 
    }

    void clear() {
        freeTree(root);
        root = nullptr;
        count = 0;
    }
};

int main() {
    BST bst;
    bst.clear();
}
