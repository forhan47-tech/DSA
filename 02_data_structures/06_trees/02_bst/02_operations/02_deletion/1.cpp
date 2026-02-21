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

    Node* findMin(Node* node) {
        while (node->left != nullptr) 
            node = node->left;
        return node;
    }

    Node* remove(Node* node, int val) {
        if (node == nullptr) return node;
        if (val < node->data) node->left = remove(node->left, val);
        else if (val > node->data) node->right = remove(node->right, val);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void remove(int val) {
        root = remove(root, val);
    }
};

int main() {
    BST tree;
}
