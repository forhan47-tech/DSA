#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    s.assign("Hello"); // assign C-string
    cout << s << endl;         

    s.assign(4, '*'); // assign 4 '*'
    cout << s << endl;
}
