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

    bool freeChild(Node* curr, int key) {
        if (!curr) return false;

        bool found = false;
        vector<Node*> newChild;

        for (Node* cld : curr->child) {
            if (cld->data == key) {
                freeSubTree(cld);
                found = true;
            } else {
                if (freeChild(cld, key)) found = true;
                newChild.push_back(cld);
            }
        }

        curr->child = std::move(newChild);
        return found;
    }

    void freeSubTree(Node* curr) {
        if (!curr) return;
        for (auto cld : curr->child) {
            freeSubTree(cld);
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
            freeSubTree(root);
            root = nullptr;
        } else {
            if (!freeChild(root, key)) {
                cout << "Node " << key << " not found!" << endl;
            }
        }
    }
};

int main() {
    GeneralTree tr;
    tr.cut(2); 
}
