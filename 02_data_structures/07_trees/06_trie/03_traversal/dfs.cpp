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
private:
    Node* root;

    void dfs(Node* curr, string res = "") {
        if (!curr) return;

        if (curr->isEnd) {
            cout << res << endl;
        }

        for (auto& [ch, next] : curr->child) {
            dfs(next, res + ch);
        }
    }

public:
    Trie() {
        root = new Node(); 
    }

    void print() {
        dfs(root);
    }
};

int main() {
    Trie t;
    t.print();
}
