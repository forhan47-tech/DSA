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
    int preIdx;

    int findIndex(const vector<int>& inorder, int lf, int rt, int val) {
        for (int i = lf; i <= rt; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }

    Node* buildTree(const vector<int>& inorder, const vector<int>& preorder, int lf, int rt) {
        if (lf > rt) return nullptr;

        Node* root = new Node(preorder[preIdx++]);  

        if (lf == rt) return root;

        int pos = findIndex(inorder, lf, rt, root->data);

        root->left = buildTree(inorder, preorder, lf, pos - 1);
        root->right = buildTree(inorder, preorder, pos + 1, rt);

        return root;
    }

public:
    BinaryTree() {
        root = nullptr;
        preIdx = -1;
    }

    void insert(const vector<int>& inorder, const vector<int>& preorder) {
        preIdx = 0;
        root = buildTree(inorder, preorder, 0, inorder.size() - 1);
    }
};

int main() {
    BinaryTree bt;
    vector<int> inorder  = {4, 2, 5, 1, 3};
    vector<int> preorder = {1, 2, 4, 5, 3};
    bt.insert(inorder, preorder);
}
