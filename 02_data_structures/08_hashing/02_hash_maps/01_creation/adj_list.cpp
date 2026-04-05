#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Node {
public:
    int key;
    string value;

    Node(int k, const string& v) { 
        key = k; 
        value = v;
    }
};

class HashMap {
    int slots;                       // number of buckets
    vector<list<Node>> map;          // each bucket stores Node objects

    int hashFunction(int key) const {
        return abs(key) % slots;     // simple modulo hash
    }

public:
    HashMap(int v) {
        slots = v;
        map.resize(v);
    }
};

int main() {
    HashMap hm(7);
    return 0;
}
