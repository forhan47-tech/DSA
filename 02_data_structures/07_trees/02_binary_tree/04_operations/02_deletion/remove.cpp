#include <iostream>
#include <queue>
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

    void deleteDeepest(Node* deepest) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left) {
                if (curr->left == deepest) {
                    delete curr->left;
                    curr->left = nullptr;
                    return;
                } else {
                    q.push(curr->left);
                }
            }

            if (curr->right) {
                if (curr->right == deepest) {
                    delete curr->right;
                    curr->right = nullptr;
                    return;
                } else {
                    q.push(curr->right);
                }
            }
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void remove(int key) {
        if (!root) return;

        if (!root->left && !root->right) {
            if (root->data == key) {
                delete root;
                root = nullptr;
            }
            return;
        }

        queue<Node*> q;
        q.push(root);
        Node* keyNode = nullptr;
        Node* lastNode = nullptr;

        while (!q.empty()) {
            lastNode = q.front();
            q.pop();

            if (lastNode->data == key) 
                keyNode = lastNode;

            if (lastNode->left) 
                q.push(lastNode->left);

            if (lastNode->right) 
                q.push(lastNode->right);
        }

        if (keyNode) {
            keyNode->data = lastNode->data;
            deleteDeepest(lastNode);
        }
    }
};

int main() {
    BinaryTree bt;
}
