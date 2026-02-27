#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;                      
    vector<list<int>> table;         

    int hashFunction(int value) {
        return abs(value) % slots;
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
    }

    bool search(int value) {
        int idx = hashFunction(value);
        for (int x : table[idx]) {
            if (x == value) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    HashTable ht(7);
    return 0;
}
