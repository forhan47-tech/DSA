#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool isEndOfWord;

    Node() {
        isEndOfWord = false;
    }
};

class Trie {
    Node* root;

    int sizeHelper(Node* node) {
    if (!node) return 0;
    int count = node->isEndOfWord ? 1 : 0;
    for (auto& [ch, child] : node->children) {
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
