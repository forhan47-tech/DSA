#include <iostream>
using namespace std;

int main() {
     int r = 4, c = 3;

    int mat[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    int pos = 1; // row -> 1

    for(int i = pos; i < r-1; i++) {
        for(int j = 0; j < c; j++) {
            mat[i][j] = mat[i+1][j]; // Shift rows upward
        }
    }
    r--; // reduce row count

    cout << "Output:\n";
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}
