#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int slots;                       
    vector<list<int>> table;        

    int hashFunction(int val) {
        return abs(val) % slots;
    }

public:
    HashTable(int v) {
        slots = v;
        table.resize(v);
    }

    void display() const {
        for (int i = 0; i < slots; i++) {
            cout << i << ": ";
            for (int x : table[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);
}