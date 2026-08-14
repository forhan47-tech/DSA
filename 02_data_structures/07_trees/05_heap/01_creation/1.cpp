#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Heap {
    vector<int> arr;
    bool isMinHeap; // true → Min Heap, false → Max Heap

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

    void heapifyUp(int i) {
        while (i > 0 && compare(arr[i], arr[parent(i)])) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int n = arr.size();
        while (true) {
            int l = left(i), r = right(i), best = i;
            if (l < n && compare(arr[l], arr[best])) best = l;
            if (r < n && compare(arr[r], arr[best])) best = r;
            if (best != i) {
                swap(arr[i], arr[best]);
                i = best;
            } else break;
        }
    }

public:
    Heap(bool type = false) { isMinHeap = type; }

    // Core Operations
    void insert(int val) {
        arr.push_back(val);
        heapifyUp(arr.size() - 1);
    }

    int peek() {
        if (arr.empty()) throw runtime_error("Heap empty");
        return arr[0];
    }

    void pop() {
        if (arr.empty()) throw runtime_error("Heap empty");
        arr[0] = arr.back();
        arr.pop_back();
        if (!arr.empty()) heapifyDown(0);
    }

    void printHeap() {
        for (int x : arr) cout << x << " ";
        cout << endl;
    }

    // Property Functions
    int size() { return arr.size(); }
    bool isEmpty() { return arr.empty(); }
    int height() { return arr.empty() ? 0 : (int)log2(arr.size()) + 1; }
    bool isLeaf(int i) { return left(i) >= arr.size(); }
    int getParent(int i) { return (i > 0) ? arr[parent(i)] : -1; }
    vector<int> getChildren(int i) {
        vector<int> children;
        if (left(i) < arr.size()) children.push_back(arr[left(i)]);
        if (right(i) < arr.size()) children.push_back(arr[right(i)]);
        return children;
    }

    // Heapsort using this heap
    vector<int> heapsort() {
        vector<int> copy = arr;
        vector<int> sorted;
        Heap tempHeap(isMinHeap);
        for (int x : copy) tempHeap.insert(x);
        while (!tempHeap.isEmpty()) {
            sorted.push_back(tempHeap.peek());
            tempHeap.pop();
        }
        return sorted;
    }

    // Validation function
    bool isValidHeap() {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int l = left(i), r = right(i);
            if (l < n && !compare(arr[i], arr[l])) return false;
            if (r < n && !compare(arr[i], arr[r])) return false;
        }
        return true;
    }
};
