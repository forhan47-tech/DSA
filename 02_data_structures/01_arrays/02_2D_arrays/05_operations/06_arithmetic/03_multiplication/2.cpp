#include <iostream>
using namespace std;

int main() {
    int A[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int k = 3; // scalar value
    int C[2][3];

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            C[i][j] = k * A[i][j];
        }
    }

    cout << "Scalar Multiplication:" << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
