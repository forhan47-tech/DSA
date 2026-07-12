#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& v, int n, int i) {
    int root = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && v[left] > v[root]) root = left;
    if (right < n && v[right] > v[root]) root = right;

    if (root != i) {
        swap(v[i], v[root]);  // swap root with largest
        heapify(v, n, root);
    }
}

void heapSort(vector<int>& v) {
    int n = v.size();

    for (int i = n/2-1; i >= 0; i--) {
        heapify(v, n, i);  // build max heap
    }

    for (int i = n-1; i > 0; i--) {
        swap(v[0], v[i]);  // Move current root to end
        heapify(v, i, 0);  // Heapify reduced heap
    }
}

int main() {
    vector<int> v = {5, 3, 8, 4, 2};
    heapSort(v);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " ";
}
