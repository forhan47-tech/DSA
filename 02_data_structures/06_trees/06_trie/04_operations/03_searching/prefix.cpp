#include <iostream>
#include <unordered_map>
#include <string>
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
private:
    Node* root;

public:
    Trie() { 
        root = new Node(); 
    }

    bool startsWith(const string& prefix) { 
        Node* curr = root; 
        for (char ch : prefix) { 
            if (!curr->child[ch]) 
                return false; 
            curr = curr->child[ch]; 
        } 
        return true; 
    }
};

int main() {
    Trie trie;
}
