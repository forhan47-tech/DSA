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

class BinaryTree {
    Node* root;

    Node* buildTree(const vector<int>& inorder, int lf, int rt) {
        if (lf > rt) 
            return nullptr;

        int mid = (lf + rt) / 2;
        Node* root = new Node(inorder[mid]);  
        root->left = buildTree(inorder, lf, mid - 1);
        root->right = buildTree(inorder, mid + 1, rt);
        return root;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(const vector<int>& inorder) {
        root = buildTree(inorder, 0, inorder.size() - 1);
    }
};

int main() {
    BinaryTree bt;
    vector<int> inorder = {20, 30, 40, 50, 60, 70, 80};
}
