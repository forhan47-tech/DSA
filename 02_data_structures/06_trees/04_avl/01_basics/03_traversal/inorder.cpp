#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
    Node* root;

    void inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

public:
    AVL() {
        root = nullptr;
    }

    void dfs_inorder() { 
        cout << "Inorder: "; 
        inorder(root); 
        cout << endl; 
    }
};

int main() {
    AVL tree;
}
