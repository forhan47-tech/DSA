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
        left = right =nullptr;
    }
};

class BinaryTree {
    Node* root;

    int findIndex(vector<int>& inorder, int val, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    Node* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        Node* root = new Node(preorder[preIndex++]);
        int inIndex = findIndex(inorder, root->data, inStart, inEnd);
        root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1);
        root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd);
        return root;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        root = buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1);    
    }
};

int main() {
    BinaryTree bt;
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> inorder  = {4, 2, 5, 1, 3};
}
