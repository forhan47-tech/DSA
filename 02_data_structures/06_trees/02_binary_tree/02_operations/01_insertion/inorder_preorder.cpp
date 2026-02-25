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
        left = right =nullptr;
    }
};

class BinaryTree {
    Node* root;

    Node* buildTree(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int,int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) 
            return nullptr;

        Node* node = new Node(preorder[preStart]);
        int inRoot = inMap[node->data];
        int numsLeft = inRoot - inStart;

        node->left = buildTree(preorder, preStart+1, preStart+numsLeft,
                               inorder, inStart, inRoot-1, inMap);
        node->right = buildTree(preorder, preStart+numsLeft+1, preEnd,
                                inorder, inRoot+1, inEnd, inMap);
        return node;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for (int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
        root = buildTree(preorder, 0, preorder.size()-1,
                         inorder, 0, inorder.size()-1, inMap);
    }
};

int main() {
    BinaryTree bt;
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> inorder  = {4, 2, 5, 1, 3};
}
