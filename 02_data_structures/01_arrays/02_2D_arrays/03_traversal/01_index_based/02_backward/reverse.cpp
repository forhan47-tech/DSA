#include <iostream>
using namespace std;

int main() {
    int r = 3, c = 3;
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Reverse traversal:\n";
    for(int i=r-1; i>=0; i--) {          // start from last row
        for(int j=c-1; j>=0; j--) {      // start from last column
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
