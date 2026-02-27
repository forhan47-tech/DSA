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

    int countLeaves(Node* curr) const {
        if (!curr) {
            return 0;
        }

        if (curr->child.empty()) {
            return 1;
        }

        int total = 0;
        for (auto ch : curr->child) {
            total += countLeaves(ch);
        }
        return total;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    int leaves() { 
        return countLeaves(root); 
    }
};

int main() {
    GeneralTree tr;
}
