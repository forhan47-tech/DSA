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

class BinaryTree {
    Node* root;

    bool search(Node* curr, int key) {
        if (!curr) 
            return false;

        if (curr->data == key) 
            return true;

        return search(curr->left, key) || search(curr->right, key);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    bool find(int key) { 
        return search(root, key); 
    }
};

int main() {
    BinaryTree bt;
}