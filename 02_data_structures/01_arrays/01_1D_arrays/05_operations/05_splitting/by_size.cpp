#include <iostream>
using namespace std;

void splitBySize(int arr[], int n, int size) {
    for (int i = 0; i < n; i++) {
        if (i % size == 0) cout << "\nSubarray: ";
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chunkSize = 3;
    splitBySize(arr, n, chunkSize);
}
