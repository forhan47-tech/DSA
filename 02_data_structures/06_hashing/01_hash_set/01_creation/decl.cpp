#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashSet {
    int slots;                      // number of buckets
    vector<list<int>> table;        // each bucket is a list

    int hashFunction(int val) {
        return abs(val) % slots;    // simple modulo hash
    }

public:
    HashSet(int v) {
        slots = v;
        table.resize(v);
    }
};

int main() {
    HashSet hs(7);
    return 0;
}
