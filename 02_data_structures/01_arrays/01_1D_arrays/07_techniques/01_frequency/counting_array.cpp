#include <iostream>
using namespace std;


void frequencyCount(int arr[], int n) {
    int freq[100] = {};  // Initialize frequency array to 0

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    cout << "Frequency:\n";
    for (int i = 0; i < 100; i++) {
        if (freq[i] > 0) {
            cout << i << " -> " << freq[i] << "\n";
        }
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4};
    int n = size(arr);
    frequencyCount(arr, n);
}
