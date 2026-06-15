#include <iostream>
using namespace std;

void addArrays(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }
}

int main() {
    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {10, 20, 30, 40, 50};
    int C[5];

    addArrays(A, B, C, 5);

    cout << "Output: ";
    for (int i = 0; i < 5; i++) cout << C[i] << " ";
}
