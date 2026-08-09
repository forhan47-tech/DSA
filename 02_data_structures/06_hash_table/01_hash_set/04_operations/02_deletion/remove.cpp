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

    void remove(int value) {
        int idx = hashFunction(value);
        table[idx].remove(value); 
    }
};

int main() {
    HashSet hs(7);
    hs.remove(5);
    return 0;
}
