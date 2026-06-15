#include <iostream>
#include <unordered_map>
using namespace std;

void frequencyCount(int arr[], int n) {
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++; // Count occurrence of arr[i]
    }

    for (auto p : freq) {
        cout << p.first << " occurs " << p.second << " times\n";
    }
}

int main() {
    int arr[7] = {10, 20, 10, 30, 20, 10, 40};
    frequencyCount(arr, 7);
}
