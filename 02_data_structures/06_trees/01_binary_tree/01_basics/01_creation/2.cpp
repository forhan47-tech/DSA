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

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x; // new root
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y; // new root
    }

    Node* insert(Node* node, int val) {
        // Normal BST insertion
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        else return node; // duplicates not allowed

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get balance factor
        int balance = getBalance(node);

        // Balance cases
        // Left Left
        if (balance > 1 && val < node->left->data)
            return rightRotate(node);

        // Right Right
        if (balance < -1 && val > node->right->data)
            return leftRotate(node);

        // Left Right
        if (balance > 1 && val > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left
        if (balance < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // unchanged
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVL() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void displayInorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // triggers rotation
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.displayInorder(); // Balanced AVL tree
}
