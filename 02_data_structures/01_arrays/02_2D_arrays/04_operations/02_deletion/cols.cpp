#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    int pos = 2; // column -> 2

    for(int i=0; i<rows; i++) {
        for(int j=pos; j<cols-1; j++) {
            mat[i][j] = mat[i][j+1];  // Shift columns left
        }
    }
    cols--; // reduce column count

    cout << "Output:\n";
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}
