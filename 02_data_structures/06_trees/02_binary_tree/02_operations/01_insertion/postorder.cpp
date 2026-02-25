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
    int idx;

    Node* buildTree(const vector<int>& seq) {
        if (idx < 0 || seq[idx] == -1) {
            idx--;
            return nullptr;
        }

        Node* root = new Node(seq[idx--]);
        root->right = buildTree(seq);
        root->left = buildTree(seq);
        return root;
    }

public:
    BinaryTree() {
        root = nullptr;
        idx = -1;
    }

    void insert(const vector<int>& seq) {
        idx = seq.size()-1;
        root = buildTree(seq);
    }
};

int main() {
    BinaryTree bt;
    vector<int> postorder = {-1, -1, 4, -1, -1, 5, 2, -1, -1, 3, 1};
    bt.insert(postorder);
}
