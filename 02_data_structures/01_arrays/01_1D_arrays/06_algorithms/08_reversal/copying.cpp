#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int rev[n];

    for(int i = 0; i < n; i++) {
        rev[i] = arr[n-i-1];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = rev[i];
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n);

    cout << "Reversed array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
