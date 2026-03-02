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

    int depthHelper(Node* curr, int key, int level) {
        if (!curr) return -1;

        if (curr->data == key) return level;

        for (auto cld : curr->child) {
            int depth = depthHelper(cld, key, level + 1);
            if (depth != -1) return depth;
        }
        return -1;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    int depth(int key) {
        return depthHelper(root, key, 0);
    }
};

int main() {
    GeneralTree tr;
}
