#include <iostream>
using namespace std;

int main() {
    int r = 3, c = 3;
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Step 1: Transpose
    for(int i=0; i<r; i++){
        for(int j=i; j<c; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each column
    for(int j=0; j<c; j++){
        for(int i=0; i<r/2; i++){
            swap(mat[i][j], mat[r-i-1][j]);
        }
    }

    cout << "90 degree counter-clockwise rotation:" << endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}
