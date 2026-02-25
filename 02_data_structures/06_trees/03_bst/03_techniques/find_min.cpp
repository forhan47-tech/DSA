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

    Node* findMin(Node* root) {
        if (!root) 
            return nullptr;

        while (root->left) 
            root = root->left;
        return root;
    }

public:
    BST() {
        root = nullptr;
    }

    int findMin() {
        Node* minNode = findMin(root);
        if (!minNode) 
            throw runtime_error("Tree is empty!");
        return minNode->data;
    }
};

int main() {
    BST bst;
}