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

    void inorder(Node* curr) {
        if (!curr) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }

public:
    AVL() {
        root = nullptr;
    }

    void dfs() { 
        cout << "Inorder: "; 
        inorder(root); 
        cout << endl; 
    }
};

int main() {
    AVL avl;
    avl.dfs(); 
}
