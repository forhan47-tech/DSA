#include <iostream>
using namespace std;

void merge(int A[], int nA, int B[], int nB, int C[]) {
    int k = 0;

    // Copy A
    for(int i = 0; i < nA; i++) { 
        C[k++] = A[i];
    }

    // Copy B
    for(int j = 0; j < nB; j++) {
        C[k++] = B[j];
    }
}

int main() {
    int A[] = {1, 2, 3};
    int B[] = {4, 5, 6};
    int nA = size(A), nB =size(B);
    int C[nA+nB];

    merge(A, nA, B, nB, C);

    cout << "Merged array: ";
    for(int i = 0; i < nA+nB; i++) {
        cout << C[i] << " ";
    }
}
