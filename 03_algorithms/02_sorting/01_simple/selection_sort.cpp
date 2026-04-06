#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (v[j] < v[minIdx]) {
                minIdx = j;
            }
        }
        swap(v[i], v[minIdx]); // place minimum at correct position
    }
}

int main() {
    vector<int> v = {5, 3, 8, 4, 2};
    selectionSort(v);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " "; 
}
