#include <iostream>
using namespace std;

int mergeArray(int A[], int n1, int B[], int n2, int merged[]) {
    int k = 0;
    for (int i = 0; i < n1; i++) {
        if (A[i] % 2 == 0) merged[k++] = A[i];
    }
    for (int j = 0; j < n2; j++) {
        if (B[j] % 2 == 0) merged[k++] = B[j];
    }
    return k; // new size
}

int main() {
    int A[] = {10, 21, 30, 41, 50};
    int B[] = {12, 33, 44, 55};
    int nA = size(A), nB = size(B);
    int C[nA + nB];

    int n = mergeArray(A, nA, B, nB, C);

    cout << "Merged Array: ";
    for (int i = 0; i < n; i++) cout << C[i] << " ";
}
