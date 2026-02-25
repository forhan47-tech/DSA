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


    void clear(Node* root) {
        if (root == nullptr) 
            return;

        clear(root->left);
        clear(root->right);
        delete root;
    }

public:
    BST() {
        root = nullptr;
        count = 0;
    }

    ~BST() { 
        clear(root); 
    }

    int size() const { 
        return count; 
    }

    void clear() {
        clear(root);
        root = nullptr;
        count = 0;
    }
};

int main() {
    BST bst;
    bst.clear();
}
