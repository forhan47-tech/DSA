#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Heap {
    vector<int> v;
    bool isMinHeap; // true → Min Heap, false → Max Heap

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

public:
    Heap(bool flag = false) { 
        isMinHeap = flag; 
    }

    int height() { 
        return v.empty() ? 0 : (int)log2(v.size())+1; 
    }
};

int main() {
    Heap h;
    cout << "Height: " << h.height() << endl;
}
