#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;                      // number of buckets
    vector<list<int>> table;        // each bucket is a list

    int hashFunction(int val) {
        return abs(val) % slots;    // simple modulo hash
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
    }
};

int main() {
    HashTable ht(7);
    return 0;
}
