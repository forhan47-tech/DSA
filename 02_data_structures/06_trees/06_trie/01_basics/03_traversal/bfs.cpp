#include <iostream>
#include <unordered_map>
#include <queue>
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

    void bfsTraversal() {
    queue<pair<Node*, string>> q;
    q.push({root, ""});

    while (!q.empty()) {
        auto [node, prefix] = q.front();
        q.pop();

        if (node->isEndOfWord) {
            cout << prefix << endl;
        }

        for (auto& [ch, child] : node->children) {
            q.push({child, prefix + ch});
        }
    }
}

};

int main() {
    Trie trie;
}
