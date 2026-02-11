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
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            B[i][j] = A[i][n-j-1]; // flip left ↔ right
        }
    }

    cout << "Horizontal Reflection:" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << B[i][j] << " ";
        cout << endl;
    }
}
