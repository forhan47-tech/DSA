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

class BST {
    Node* root;


public:
    BST() {
        root = nullptr;
    }

    void levelOrder() {
        if (root == nullptr) {
            cout << "Tree is empty!\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "Level Order Traversal: ";
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.levelOrder();
}
