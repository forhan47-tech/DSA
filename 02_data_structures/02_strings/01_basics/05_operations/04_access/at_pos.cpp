#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "World";

    // Index-based access
    cout << "First char: " << s[0] << endl;
    cout << "Last char: " << s[s.length() - 1] << endl;

    // Using at() (throws exception if out of range)
    cout << "Third char: " << s.at(2) << endl;

    return 0;
}
