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
        auto it = curr->child.begin();

        while (it != curr->child.end()) {
            if ((*it)->data == key) {
                freeSubTree(*it);
                it = curr->child.erase(it);
                found = true;
            } else {
                if (freeChild(*it, key)) found = true;
                ++it;
            }
        }
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
