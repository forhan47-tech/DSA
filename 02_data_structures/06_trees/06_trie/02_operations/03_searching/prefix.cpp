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

public:
    Trie() { 
        root = new Node(); 
    }

    bool startsWith(const string& prefix) { 
        Node* node = root; 
        for (char ch : prefix) { 
            if (!node->children[ch]) 
                return false; 
            node = node->children[ch]; 
        } 
        return true; 
    }
};

// Demo
int main() {
    Trie trie;
}