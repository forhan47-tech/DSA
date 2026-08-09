#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashSet {
    int slots;                      
    vector<list<int>> table;         

    int hashFunction(int value) {
        return abs(value) % slots;
    }

public:
    HashSet(int v) {
        slots = v;
        table.resize(v);
    }

    bool search(int val) {
        int idx = hashFunction(val);
        for (int key : table[idx]) {
            if (key == val) {
                return true;   
            }
        }
        return false;         
    }
};

int main() {
    HashSet hs(7);
    hs.search(5);
    return 0;
}
