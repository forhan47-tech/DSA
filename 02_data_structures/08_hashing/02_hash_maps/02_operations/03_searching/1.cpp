#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;  
    vector<list<pair<int, string>>> table;  
    int count;  // track number of elements

    int hashFunction(int key) {
        return key % slots;
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
        count = 0;
    }

    string search(int key) {
        int idx = hashFunction(key);
        for (auto &kv : table[idx]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        return "Not Found";
    }
};

int main() {
    HashTable ht(7);

    return 0;
}
