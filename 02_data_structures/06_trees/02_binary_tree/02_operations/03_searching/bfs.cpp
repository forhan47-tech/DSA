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

    bool searchBFS(Node* root, int key) {
        if (!root) 
            return false;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data == key) 
                return true;

            if (curr->left) 
                q.push(curr->left);

            if (curr->right) 
                q.push(curr->right);
        }
        return false;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    bool search(int key) { 
        return searchBFS(root, key); 
    }
};

int main() {
    BinaryTree bt;
}
