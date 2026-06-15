#include <iostream>
using namespace std;

void scalarMultiplication(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * k; // multiply each element by scalar
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int k = 3;

    scalarMultiplication(arr, 5, k);

    cout << "Output: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
