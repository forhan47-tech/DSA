#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // optimization: stop if already sorted
    }
}

int main() {
    vector<int> v = {5, 3, 8, 4, 2};
    bubbleSort(v);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " "; 
}
