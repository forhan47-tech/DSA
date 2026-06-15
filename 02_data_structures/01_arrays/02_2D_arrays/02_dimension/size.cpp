#include <iostream>
using namespace std;

int main() {
    int mat[2][2] = { {10, 20}, {30, 40} };

    int r = size(mat);      // number of rows
    int c = size(mat[0]);   // number of columns

    cout << "Matrix Rows: " << r << endl;
    cout << "Matrix Cols: " << c << endl;
}
