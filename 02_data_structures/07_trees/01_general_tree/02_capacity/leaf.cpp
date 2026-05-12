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

    int countleaf(Node* curr) const {
        if (!curr) return 0;

        if (curr->child.empty()) return 1;

        int total = 0;
        for (auto cld : curr->child) {
            total += countleaf(cld);
        }
        return total;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    int leaf() { 
        return countleaf(root); 
    }
};

int main() {
    GeneralTree tr;
}
