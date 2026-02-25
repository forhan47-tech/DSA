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

    int findDepth(Node* curr, int key, int level) {
    if (!curr) 
        return -1;

    if (curr->data == key) 
        return level;

    for (auto ch : curr->child) {
        int depth = findDepth(ch, key, level + 1);
        if (depth != -1) 
            return depth;
    }
    return -1;
}

public:
    GeneralTree() {
        root = nullptr;
    }

    int depth(int key) {
        return findDepth(root, key, 0);
    }
};

int main() {
    GeneralTree tr;
}