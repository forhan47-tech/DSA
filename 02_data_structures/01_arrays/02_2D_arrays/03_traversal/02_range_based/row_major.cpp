#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Output:" << endl;
    for(auto &r : A){          // iterate over each row
        for(auto &c : r){   // iterate over each element in row
            cout << c << " ";
        }
        cout << endl;
    }
}
