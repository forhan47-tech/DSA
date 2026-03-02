#include <iostream>
#include <vector>
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
    int count;

    Node* buildTree(Node* root, int val) {
        if (!root) {
            count++;
            return new Node(val);
        }

        if (val < root->data) 
            root->left = buildTree(root->left, val);
        else if (val > root->data) 
            root->right = buildTree(root->right, val);

        return root;
    }

public:
    BST() {
        root = nullptr;
        count = 0;
    }

    void insert(const vector<int>& seq) {
        for (int val : seq) {
            root = buildTree(root, val);
        }
    }

    int size() const { 
        return count; 
    }
};

int main() {
    BST bst;
    vector<int> vec = {10, 5, 20, 15, 25};
    bst.insert(vec);
}
