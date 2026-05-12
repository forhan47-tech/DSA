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
    int postIdx;

    int findIndex(const vector<int>& inorder, int lf, int rt, int val) {
        for (int i = lf; i <= rt; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }

    Node* buildTree(const vector<int>& inorder, const vector<int>& postorder, int lf, int rt) {
        if (lf > rt) return nullptr;

        Node* root = new Node(postorder[postIdx--]);

        if (lf == rt) return root;

        int pos = findIndex(inorder, lf, rt, root->data);

        root->right = buildTree(inorder, postorder, pos + 1, rt);
        root->left = buildTree(inorder, postorder, lf, pos - 1);

        return root;
    }

public:
    BinaryTree() {
        root = nullptr;
        postIdx = -1;
    }

    void insert(const vector<int>& inorder, const vector<int>& postorder) {
        postIdx = postorder.size() - 1;
        root = buildTree(inorder, postorder, 0, inorder.size() - 1);
    }
};

int main() {
    BinaryTree bt;
    vector<int> inorder   = {4, 2, 5, 1, 3};
    vector<int> postorder = {4, 5, 2, 3, 1};
    bt.insert(inorder, postorder);
}
