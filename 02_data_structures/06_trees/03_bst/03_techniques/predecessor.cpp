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

    Node* findMax(Node* root) {
        while (root && root->right) 
            root = root->right;
        return root;
    }

    Node* predecessor(Node* curr, int val) {
        Node* pred = nullptr;

        while (curr) {
            if (val > curr->data) {
                pred = curr;
                curr = curr->right;
            } else if (val < curr->data) {
                curr = curr->left;
            } else {
                if (curr->left) 
                    pred = findMax(curr->left);
                break;
            }
        }
        return pred;
    }

public:
    BST() {
        root = nullptr;
    }

    int predecessor(int val) {
        Node* predNode = predecessor(root, val);
        if (!predNode) 
            throw runtime_error("Predecessor not found!");
        return predNode->data;
    }
};

int main() {
    BST bst;
}
