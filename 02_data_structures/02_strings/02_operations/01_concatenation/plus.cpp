#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = " World";

    // Using + operator
    string result = s1 + s2;
    cout << "Concatenated string: " << result << endl;

    // Using += operator
    s1 += "!!!";
    cout << "After += : " << s1 << endl;

    return 0;
}
