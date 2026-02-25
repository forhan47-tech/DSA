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

    bool search(Node* root, int val) {
        if (root == nullptr) 
            return false;

        if (root->data == val) 
            return true;

        if (val < root->data) 
            return search(root->left, val);
        else 
            return search(root->right, val);
    }

public:
    BST() {
        root = nullptr;
    }

    bool contains(int val) {
        return search(root, val);
    }
};

int main() {
    BST bst;
    cout << "Search 40: " << (bst.contains(40) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (bst.contains(25) ? "Found" : "Not Found") << endl;
}
