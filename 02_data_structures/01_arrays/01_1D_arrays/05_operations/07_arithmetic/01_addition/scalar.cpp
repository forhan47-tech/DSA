#include <iostream>
using namespace std;

void scalarAddition(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] + k; // add scalar to each element
    }
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int k = 5;

    scalarAddition(arr, 5, k);

    cout << "Output: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
