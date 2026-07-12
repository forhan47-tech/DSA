#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    bool isMinHeap; // true → Min Heap, false → Max Heap

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

public:
    Heap(bool flag = false) { isMinHeap = flag; }

    int size() { 
        return v.size(); 
    }
};

int main() {
    Heap h;
    cout << "Size: " << h.size() << endl;
}
