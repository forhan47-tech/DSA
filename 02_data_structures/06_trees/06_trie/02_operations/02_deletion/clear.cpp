#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool isEnd;

    Node() { 
        isEnd = false; 
    }
};

class Trie {
    Node* root;

    void freeTree(Node* curr) {
        if (!curr) return;
        for (auto& pair : curr->child) {
            freeTree(pair.second);
        }
        delete curr;
    }

public:
    Trie() { 
        root = new Node(); 
    }

    void clear() {
        freeTree(root);
        root = nullptr; 
    }
};

int main() {
    Trie trie;
}
