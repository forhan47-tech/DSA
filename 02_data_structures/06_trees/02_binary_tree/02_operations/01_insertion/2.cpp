#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = right = nullptr; }
};

// Helper to find index of a value in inorder
int findIndex(vector<int>& inorder, int val, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

// Recursive build function
Node* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;

    Node* root = new Node(preorder[preIndex++]);

    int inIndex = findIndex(inorder, root->data, inStart, inEnd);

    root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

// Inorder traversal to verify
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6};
    vector<int> inorder  = {4, 2, 5, 1, 6, 3};

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1);

    cout << "Inorder traversal of constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
