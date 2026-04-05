#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3];
    int n = 3;

    // Vertical reflection
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            B[i][j] = A[n-i-1][j]; // flip top ↔ bottom
        }
    }

    cout << "Vertical Reflection:" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << B[i][j] << " ";
        cout << endl;
    }
}
