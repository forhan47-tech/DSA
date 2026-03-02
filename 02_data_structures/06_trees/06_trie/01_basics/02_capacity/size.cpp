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

    int sizeHelper(Node* node) {
    if (!node) return 0;
    int count = node->isEnd ? 1 : 0;
    for (auto& [ch, child] : node->child) {
        count += sizeHelper(child);
    }
    return count;
}

public:
    Trie() { 
        root = new Node(); 
    }
    int size() {
        return sizeHelper(root);
    }
};

int main() {
    Trie trie;
}
