#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

int main() {
    int rows = 3, cols = 3;
    int mat[3][3] = {
        {9, 2, 7},
        {4, 6, 1},
        {5, 3, 8}
    };

    for(int i = 0; i < rows; i++) {
        sort(mat[i], mat[i] + cols); // sort each row
    }

    cout << "Matrix:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}
