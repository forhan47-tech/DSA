#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;                      
    vector<list<int>> table;         
    int count;                     

    int hashFunction(int value) {
        return abs(value) % slots;
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
        count = 0;
    }

    void remove(int value) {
        int idx = hashFunction(value);
        table[idx].remove(value);
        count--;
    }
};

int main() {
    HashTable ht(7);
}
