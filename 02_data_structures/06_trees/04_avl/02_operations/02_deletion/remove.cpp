#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
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

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }


    Node* findMin(Node* node) {
        Node* curr = node;
        while (curr->left) curr = curr->left;
        return curr;
    }

    Node* deleteHelper(Node* node, int key) {
        if (!node) return node;

        if (key < node->data)
            node->left = deleteHelper(node->left, key);
        else if (key > node->data)
            node->right = deleteHelper(node->right, key);
        else {
            // Node found
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteHelper(node->right, temp->data);
            }
        }

        if (!node) return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return rebalance(node);
    }


    Node* rebalance(Node* node) {
        int balance = getBalance(node);

        // LL
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        // LR
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RR
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        // RL
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    AVL() : root(nullptr) {}

    void remove(int key) { root = deleteHelper(root, key); }
};

int main() {
    AVL tree;
}