#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> child;

    Node(int val) {
        data = val;
    }
};

class GeneralTree {
    Node* root;

    bool buildTree(Node* curr, int pval, int cval) {
        if (!curr) 
            return false;

        if (curr->data == pval) {
            curr->child.push_back(new Node(cval));
            return true;
        }

        for (auto ch : curr->child) {
            if (buildTree(ch, pval, cval)) 
                return true;
        }
        return false;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void insert(int pval, int cval) {
        if (!root) {
            root = new Node(pval);
            root->child.push_back(new Node(cval));
        } else {  
            buildTree(root, pval, cval);
        }
    }
};

int main() {
    GeneralTree tr;
}