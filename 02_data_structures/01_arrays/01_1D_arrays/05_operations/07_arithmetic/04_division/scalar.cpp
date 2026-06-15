#include <iostream>
using namespace std;

void scalarDivision(int arr[], int n, int k) {
    if (k == 0) {
        cout << "Division by zero is not allowed!";
        return;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] / k; // divide each element by scalar
    }
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int k = 10;

    scalarDivision(arr, 5, k);

    cout << "Output: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
