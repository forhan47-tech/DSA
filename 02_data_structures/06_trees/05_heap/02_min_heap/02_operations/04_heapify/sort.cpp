#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }


public:
    void buildHeap(vector<int>& arr) { 
        heap = arr; 
        for (int i = heap.size()/2 - 1; i >= 0; i--) { 
            heapifyDown(i); 
        } 
    }
};

int main() {
    MinHeap mh;
}
