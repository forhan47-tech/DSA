#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    bool isMinHeap; // true → Min Heap, false → Max Heap

    int left(int i) { 
        return 2*i+1; 
    }

    int right(int i) { 
        return 2*i+2; 
    }

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

public:
    Heap(bool flag = false) { 
        isMinHeap = flag; 
    }

    bool isHeap() {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int l = left(i), r = right(i);
            if (l < n && compare(v[l], v[i])) return false;
            if (r < n && compare(v[r], v[i])) return false;
        }
        return true;
    }
};

int main() {
    Heap h;
    cout << "Is Heap? " << (h.isHeap() ? "Yes" : "No") << endl;
}
