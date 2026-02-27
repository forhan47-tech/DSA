#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashMap {
    int slots;  
    vector<list<pair<int, string>>> map;  

    int hashFunction(int key) {
        return abs(key) % slots;
    }

public:
    HashMap(int v) {
        slots = v;
        map.resize(v);
    }

    void display() {
        for (int i = 0; i < slots; i++) {
            cout << i << ": ";
            for (auto &kv : map[i]) {
                cout << "(" << kv.first << ", " << kv.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap hm(7);
    return 0;
}
