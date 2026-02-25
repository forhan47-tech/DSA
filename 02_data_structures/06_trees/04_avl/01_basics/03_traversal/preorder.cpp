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

    void preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}


public:
    AVL() {
        root = nullptr;
    }

    void dfs_preorder() { 
        cout << "Preorder: "; 
        preorder(root); 
        cout << endl; 
    }
};

int main() {
    AVL tree;
}
