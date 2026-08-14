#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool isEnd;

    Node() : isEnd(false) {}
};

class Trie {
    Node* root;

    void freeTree(Node* curr) {
        if (!curr) return;
        for (auto& [ch, next] : curr->child) {
            freeTree(next);
            delete next;
        }
        curr->child.clear();
    }

public:
    Trie() { 
        root = new Node(); 
    }

    ~Trie() { 
        clear();
        delete root;
    }

    void clear() {
        freeTree(root);
        root->isEnd = false;
    }
};

int main() {
    Trie t;
    t.clear();
}
