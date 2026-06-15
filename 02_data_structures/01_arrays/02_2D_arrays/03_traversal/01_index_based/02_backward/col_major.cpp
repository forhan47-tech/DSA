#include <iostream>
using namespace std;

int main() {
    int r = 3, c = 4;

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Column-wise reverse traversal:\n";
    for(int j=0; j<c; j++) {           // iterate columns normally
        for(int i=r-1; i>=0; i--) {      // reverse each column
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
