#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";
    string s3 = "Hello";

    // Equality
    if (s1 == s3)
        cout << "s1 and s3 are equal" << endl;

    // Inequality
    if (s1 != s2)
        cout << "s1 and s2 are not equal" << endl;

    // Lexicographical comparison
    if (s1 < s2)
        cout << "s1 comes before s2" << endl;

    return 0;
}
