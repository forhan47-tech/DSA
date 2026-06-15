#include <iostream>
using namespace std;

void splitArray(int arr[], int n, int even[], int &u, int odd[], int &v) {
    u = v = 0; // reset counts

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even[u++] = arr[i];  // add to even
        else
            odd[v++] = arr[i];   // add to odd
    }
}

int main() {
    int arr[] = {10, 15, 20, 25, 30, 35, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int even[n], odd[n];
    int u, v;

    splitArray(arr, n, even, u, odd, v);

    cout << "Even array: ";
    for (int i = 0; i < u; i++) cout << even[i] << " ";

    cout << "\nOdd array: ";
    for (int i = 0; i < v; i++) cout << odd[i] << " ";
}
