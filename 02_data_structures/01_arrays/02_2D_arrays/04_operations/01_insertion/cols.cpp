#include <iostream>
using namespace std;

int main() {
    int r = 3, c = 3;

    int mat[3][4] = {   
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };  // allocate extra space

    int vec[3] = {10, 11, 12};
    int pos = 1; // col -> 1

    for(int i = 0; i < r; i++) {
        for(int j = c; j > pos; j--) {
            mat[i][j] = mat[i][j-1];   // Shift columns to the right
        }
        mat[i][pos] = vec[i]; // insert new column
    }
    c++;

    cout << "Output:\n";
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}
