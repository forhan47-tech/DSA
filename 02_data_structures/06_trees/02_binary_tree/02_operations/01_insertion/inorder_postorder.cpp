#include <iostream>
#include <vector>
#include <unordered_map>
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

    Node* buildTree(vector<int>& postorder, int postStart, int postEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int,int>& inMap) {
        if (postStart > postEnd || inStart > inEnd) 
            return nullptr;

        Node* node = new Node(postorder[postEnd]);
        int inRoot = inMap[node->data];
        int numsLeft = inRoot - inStart;

        node->left = buildTree(postorder, postStart, postStart+numsLeft-1,
                               inorder, inStart, inRoot-1, inMap);
        node->right = buildTree(postorder, postStart+numsLeft, postEnd-1,
                                inorder, inRoot+1, inEnd, inMap);
        return node;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void buildFromPostIn(vector<int>& postorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for (int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
        root = buildTree(postorder, 0, postorder.size()-1,
                         inorder, 0, inorder.size()-1, inMap);
    }
};

int main() {
    BinaryTree bt;
    vector<int> postorder = {4, 5, 2, 3, 1};
    vector<int> inorder   = {4, 2, 5, 1, 3};
}