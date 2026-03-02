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
        auto it = curr->child.begin();

        while (it != curr->child.end()) {
            if ((*it)->data == key) {
                freeTree(*it);
                it = curr->child.erase(it);
                found = true;
            } else {
                if (detach(*it, key)) found = true;
                ++it;
            }
        }
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
