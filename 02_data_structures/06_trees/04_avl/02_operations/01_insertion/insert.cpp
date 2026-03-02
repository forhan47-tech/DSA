#include <iostream>
#include <algorithm>
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

    int getHeight(Node* curr) {
        return curr ? curr->height : 0;
    }

    int getBalance(Node* curr) {
        return curr ? getHeight(curr->left) - getHeight(curr->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insert(Node* curr, int key) {
        if (!curr) return new Node(key);

        if (key < curr->data)
            curr->left = insert(curr->left, key);
        else if (key > curr->data)
            curr->right = insert(curr->right, key);
        else
            return curr; // duplicates not allowed

        curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));

        return balance(curr, key);
    }

    Node* balance(Node* curr, int key) {
        int balanceFactor = getBalance(curr);

        // LL
        if (balanceFactor > 1 && key < curr->left->data)
            return rightRotate(curr);

        // RR
        if (balanceFactor < -1 && key > curr->right->data)
            return leftRotate(curr);

        // LR
        if (balanceFactor > 1 && key > curr->left->data) {
            curr->left = leftRotate(curr->left);
            return rightRotate(curr);
        }

        // RL
        if (balanceFactor < -1 && key < curr->right->data) {
            curr->right = rightRotate(curr->right);
            return leftRotate(curr);
        }

        return curr;
    }

public:
    AVL() {
        root = nullptr;
    }

    void insert(int key) { 
        root = insert(root, key); 
    }
};

int main() {
    AVL avl;
}
