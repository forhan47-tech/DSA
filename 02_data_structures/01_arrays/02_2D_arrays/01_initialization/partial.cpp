#include <iostream>
using namespace std;

int main() {
    int mat[2][3] = {
        {1}, 
        {4, 5}
    }; // missing values auto-filled with 0

    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}
