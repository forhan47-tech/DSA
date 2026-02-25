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

    void postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

public:
    AVL() {
        root = nullptr;
    }

    void dfs_postorder(){ 
        cout << "Postorder: "; 
        postorder(root); 
        cout << endl; 
    }
};

int main() {
    AVL tree;
}
