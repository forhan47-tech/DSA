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

    bool search(Node* node, int val) {
        if (node == nullptr) 
            return false;

        if (node->data == val) 
            return true;

        if (val < node->data) 
            return search(node->left, val);
        else 
            return search(node->right, val);
    }

public:
    BST() {
        root = nullptr;
    }

    bool search(int val) {
        return search(root, val);
    }
};

int main() {
    BST tree;
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;
}
