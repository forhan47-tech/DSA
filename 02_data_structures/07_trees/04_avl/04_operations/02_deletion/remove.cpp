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

    Node* findMin(Node* curr) {
        while (curr && curr->left) curr = curr->left;
        return curr;
    }

    Node* deleteHelper(Node* curr, int key) {
        if (!curr) return curr;

        if (key < curr->data)
            curr->left = deleteHelper(curr->left, key);
        else if (key > curr->data)
            curr->right = deleteHelper(curr->right, key);
        else {
            // Node found
            if (!curr->left || !curr->right) {
                Node* temp = curr->left ? curr->left : curr->right;
                if (!temp) {
                    temp = curr;
                    curr = nullptr;
                } else {
                    *curr = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMin(curr->right);
                curr->data = temp->data;
                curr->right = deleteHelper(curr->right, temp->data);
            }
        }

        if (!curr) return curr;

        curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
        return rebalance(curr);
    }

    Node* rebalance(Node* curr) {
        int balance = getBalance(curr);

        // LL
        if (balance > 1 && getBalance(curr->left) >= 0)
            return rightRotate(curr);

        // LR
        if (balance > 1 && getBalance(curr->left) < 0) {
            curr->left = leftRotate(curr->left);
            return rightRotate(curr);
        }

        // RR
        if (balance < -1 && getBalance(curr->right) <= 0)
            return leftRotate(curr);

        // RL
        if (balance < -1 && getBalance(curr->right) > 0) {
            curr->right = rightRotate(curr->right);
            return leftRotate(curr);
        }

        return curr;
    }

public:
    AVL() {
        root = nullptr;
    }

    void remove(int key) { 
        root = deleteHelper(root, key); 
    }
};

int main() {
    AVL avl;
    cout << "AVL tree created successfully!" << endl;
}
