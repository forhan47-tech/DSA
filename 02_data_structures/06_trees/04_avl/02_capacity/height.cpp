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

    int heightHelper(Node* root) {
        if (!root) 
            return 0;
        return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }

public:
    AVL() {
        root = nullptr;
    }

    int height() { 
        return heightHelper(root); 
    }
};

int main() {
    AVL avl;
    cout << "Height of tree: " << avl.height() << endl;
}
