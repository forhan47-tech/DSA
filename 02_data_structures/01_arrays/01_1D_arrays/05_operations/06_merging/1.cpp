#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 3};
    int B[] = {4, 5, 6};
    int nA = size(A), nB =size(B);
    int C[nA+nB];

    // Copy A
    for(int i = 0; i < nA; i++) { 
        C[i] = A[i];
    }

    // Copy B
    for(int i = 0; i < nB; i++) {
        C[i+nA] = B[i];
    }

    cout << "Merged array: ";
    for(int i = 0; i < nA+nB; i++) {
        cout << C[i] << " ";
    }
}
