#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s1 = "HelloWorld";
    string s2 = "HelloWorld";

    // Convert to uppercase
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    cout << "Uppercase: " << s1 << endl;
    return 0;
}
