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

    void preorder(Node* curr) {
        if (!curr) return;
        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }

public:
    AVL() {
        root = nullptr;
    }

    void dfs() { 
        cout << "Preorder: "; 
        preorder(root); 
        cout << endl; 
    }
};

int main() {
    AVL avl;
    avl.dfs();
}
