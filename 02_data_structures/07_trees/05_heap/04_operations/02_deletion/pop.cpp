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

    void heapifyDown(int i) {
        int n = v.size();
        int l = left(i), r = right(i), best = i;

        if (l < n && compare(v[l], v[best])) best = l;
        if (r < n && compare(v[r], v[best])) best = r;

        if (best != i) {
            swap(v[i], v[best]);
            heapifyDown(best);
        }
    }

public:
    Heap(bool flag = false) { 
        isMinHeap = flag; 
    }

    void pop() {
        if (v.empty()) return;
        v[0] = v.back();
        v.pop_back();
        if (!v.empty()) heapifyDown(0);
    }
};

int main() {
    Heap h;
    h.pop();
}
