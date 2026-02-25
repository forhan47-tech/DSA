#include <iostream>
#include <unordered_map>
#include <string>
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
private:
    Node* root;

    // Helper for deletion
    bool deleteHelper(Node* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (!node->isEndOfWord) return false; // word not found
            node->isEndOfWord = false;
            return node->children.empty(); // prune if no children
        }

        char ch = word[depth];
        if (deleteHelper(node->children[ch], word, depth + 1)) {
            delete node->children[ch];
            node->children.erase(ch);
            return !node->isEndOfWord && node->children.empty();
        }
        return false;
    }

public:
    Trie() { 
        root = new Node(); 
    }

    void remove(const string& word) {
        deleteHelper(root, word, 0);
    }
};

// Demo
int main() {
    Trie trie;
}
