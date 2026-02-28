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

    int findIndex(vector<int>& inorder, int val, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        Node* root = new Node(postorder[postIndex--]);
        int inIndex = findIndex(inorder, root->data, inStart, inEnd);
        root->right = buildTree(inorder, postorder, postIndex, inIndex + 1, inEnd);
        root->left = buildTree(inorder, postorder, postIndex, inStart, inIndex - 1);
        return root;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void buildFromPostIn(vector<int>& postorder, vector<int>& inorder) {
        int postIndex = postorder.size() - 1;
        root = buildTree(inorder, postorder, postIndex, 0, inorder.size() - 1);
    }
};

int main() {
    BinaryTree bt;
    vector<int> postorder = {4, 5, 2, 3, 1};
    vector<int> inorder   = {4, 2, 5, 1, 3};
}