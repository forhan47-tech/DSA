#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j]; // Shift elements one position ahead
            j--;
        }
        v[j+1] = key;
    }
}

int main() {
    vector<int> v = {5, 3, 8, 4, 2};
    insertionSort(v);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " "; 
}
