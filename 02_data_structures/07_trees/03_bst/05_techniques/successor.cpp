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

    Node* findMin(Node* root) {
        while (root && root->left) 
            root = root->left;
        return root;
    }

    Node* findSuccessor(Node* curr, int val) {
        Node* succ = nullptr;

        while (curr) {
            if (val < curr->data) {
                succ = curr;
                curr = curr->left;
            } else if (val > curr->data) {
                curr = curr->right;
            } else {
                if (curr->right) 
                    succ = findMin(curr->right);
                break;
            }
        }
        return succ;
    }

public:
    BST() {
        root = nullptr;
    }

    int successor(int val) {
        Node* succ = findSuccessor(root, val);
        if (!succ) 
            return -1; 
        return succ->data;
    }
};

int main() {
    BST bst;
}
