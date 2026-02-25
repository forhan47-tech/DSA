#include <iostream>
#include <algorithm>
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

    int findHeight(Node* root) {
        if (!root) 
            return 0;
        
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    int height() { 
        return findHeight(root); 
    }
};

int main() {
    BinaryTree bt;
    cout << "Height of tree: " << bt.height() << endl;
}
