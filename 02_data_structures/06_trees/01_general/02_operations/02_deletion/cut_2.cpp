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

    bool detach(Node* curr, int key) {
        if (!curr) return false;

        bool found = false;
        vector<Node*> newChild;

        for (Node* cld : curr->child) {
            if (cld->data == key) {
                freeTree(cld);
                found = true;
            } else {
                if (detach(cld, key)) found = true;
                newChild.push_back(cld);
            }
        }

        curr->child = std::move(newChild);
        return found;
    }

    void freeTree(Node* curr) {
        if (!curr) return;
        for (auto cld : curr->child) {
            freeTree(cld);
        }
        delete curr;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void cut(int key) {
        if (!root) {
            cout << "Tree is empty!" << endl;
            return;
        }

        if (root->data == key) {
            freeTree(root);
            root = nullptr;
        } else {
            if (!detach(root, key)) {
                cout << "Node " << key << " not found!" << endl;
            }
        }
    }
};

int main() {
    GeneralTree tr;
    tr.cut(2); 
}
