#include <iostream>
using namespace std;

int main() {
    int mat[][2] = { {10, 20}, {30, 40} };

    int rows = size(mat);      // number of rows
    int cols = size(mat[0]);   // number of columns

    cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;
    return 0;
}
