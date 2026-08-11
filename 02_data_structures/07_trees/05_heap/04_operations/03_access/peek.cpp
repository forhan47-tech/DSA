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
    Heap(bool flag = false) { 
        isMinHeap = flag; 
    }

    int peek() {
        if (v.empty()) throw runtime_error("Heap is empty");
        return v[0];
    }
};

int main() {
    Heap h;
    cout << "Peek: " << h.peek() << endl;
}
