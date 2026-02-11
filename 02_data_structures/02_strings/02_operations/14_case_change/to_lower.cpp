#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s1 = "HelloWorld";
    string s2 = "HelloWorld";

    // Convert to lowercase
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout << "Lowercase: " << s2 << endl;
    return 0;
}
