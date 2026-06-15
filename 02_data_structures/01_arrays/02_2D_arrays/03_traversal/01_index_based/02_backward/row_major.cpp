#include <iostream>
using namespace std;

int main() {
    int r = 3, c = 3;

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Row-wise reverse traversal:\n";
    for(int i=0; i<r; i++) {           // iterate rows normally
        for(int j=c-1; j>=0; j--) {      // reverse each row
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
