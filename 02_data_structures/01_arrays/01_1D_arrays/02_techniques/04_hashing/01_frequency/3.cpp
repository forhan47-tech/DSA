#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4};
    int n = size(arr);
    int freq[100] = {};  // assuming values are < 100

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    cout << "Frequencies:\n";
    for (int i = 0; i < 100; i++) {
        if (freq[i] > 0) {
            cout << i << " -> " << freq[i] << "\n";
        }
    }
}
