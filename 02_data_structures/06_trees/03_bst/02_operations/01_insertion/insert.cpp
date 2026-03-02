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

    Node* buildTree(Node* root, int key) {
        if (root == nullptr) {
            count++;
            return new Node(key);
        }

        if (key < root->data) 
            root->left = buildTree(root->left, key);
        else if (key > root->data) 
            root->right = buildTree(root->right, key);

        return root;
    }

public:
    BST() {
        root = nullptr;
        count = 0;
    }

    int size() const {
        return count;
    }

    void insert(int val) {
        root = buildTree(root, val);
    }
};

int main() {
    BST bst;
}
