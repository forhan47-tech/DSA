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

// Helper to find index in inorder
int findIndex(vector<int>& inorder, int val, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

// Recursive build function
Node* buildTree(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;

    Node* root = new Node(postorder[postIndex--]);

    int inIndex = findIndex(inorder, root->data, inStart, inEnd);

    // Build right subtree first (because postorder is Left → Right → Root)
    root->right = buildTree(inorder, postorder, postIndex, inIndex + 1, inEnd);
    root->left = buildTree(inorder, postorder, postIndex, inStart, inIndex - 1);

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
    vector<int> inorder   = {4, 2, 5, 1, 6, 3};
    vector<int> postorder = {4, 5, 2, 6, 3, 1};
    int postIndex = postorder.size() - 1;

    Node* root = buildTree(inorder, postorder, postIndex, 0, inorder.size() - 1);

    cout << "Inorder traversal of constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
