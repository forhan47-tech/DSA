#include <iostream>
using namespace std;

int main() {
    int r = 3, c = 3;

    int mat[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };    // allocate extra space

    int vec[3] = {10, 11, 12};
    int pos = 1; // row -> 1

    for(int i = r; i > pos; i--) {
        for(int j = 0; j < c; j++) {
            mat[i][j] = mat[i-1][j]; // Shift rows downward
        }
    }

    for(int j = 0; j < c; j++) {
        mat[pos][j] = vec[j]; // Insert new row
    }
    r++;

    cout << "Output:\n";
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}
