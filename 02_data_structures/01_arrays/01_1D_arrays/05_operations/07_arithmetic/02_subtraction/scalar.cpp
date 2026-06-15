#include <iostream>
using namespace std;

void scalarSubtraction(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] - k; // subtract scalar from each element
    }
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int k = 5;

    scalarSubtraction(arr, 5, k);

    cout << "Output: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
