#include <iostream>
using namespace std;

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = 3; // square matrix

    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i; j++) {
            swap(mat[i][j], mat[n-1-j][n-1-i]);
        }
    }

    cout << "Reflection:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}
