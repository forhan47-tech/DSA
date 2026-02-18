#include <iostream>
using namespace std;

void mergeSorted(int A[], int nA, int B[], int nB, int C[]) {
    int i=0, j=0, k=0;

    while(i < nA && j < nB) {
        if(A[i] < B[j]) 
        C[k++] = A[i++];
        else 
        C[k++] = B[j++];
    }
    
    while(i < nA) {
        C[k++] = A[i++];
    }

    while(j < nB) {
        C[k++] = B[j++];
    }
}

int main() {
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};
    int nA = size(A), nB = size(B);
    int C[nA+nB];

    mergeSorted(A, nA, B, nB, C);

    cout << "Merged sorted array: ";
    for(int i = 0; i < nA+nB; i++) {
        cout << C[i] << " ";
    }
}
