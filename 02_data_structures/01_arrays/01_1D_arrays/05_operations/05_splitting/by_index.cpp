#include <iostream>
using namespace std;

void splitArray(int arr[], int n, int firstHalf[], int &e, int secondHalf[], int &f) {
    int mid = n / 2;

    e = f = 0; // reset counts
    for (int i = 0; i < mid; i++) {
        firstHalf[e++] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        secondHalf[f++] = arr[i];
    }
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int firstHalf[n], secondHalf[n];
    int e, f;

    splitArray(arr, n, firstHalf, e, secondHalf, f);

    cout << "First half: ";
    for (int i = 0; i < e; i++) {
        cout << firstHalf[i] << " ";
    }

    cout << "\nSecond half: ";
    for (int i = 0; i < f; i++) {
        cout << secondHalf[i] << " ";
    }
}
