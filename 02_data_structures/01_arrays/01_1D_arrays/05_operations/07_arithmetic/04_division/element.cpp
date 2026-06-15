#include <iostream>
using namespace std;

void divideArrays(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++) {
        if (B[i] != 0) {
            C[i] = A[i] / B[i]; // element-wise division
        } else {
            cout << "Division by zero at index " << i << endl;
            C[i] = 0; // handle safely
        }
    }
}

int main() {
    int A[5] = {10, 20, 30, 40, 50};
    int B[5] = {2, 4, 5, 10, 25};
    int C[5];

    divideArrays(A, B, C, 5);

    cout << "Output: ";
    for (int i = 0; i < 5; i++) cout << C[i] << " ";
}
