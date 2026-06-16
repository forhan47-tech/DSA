#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "HelloWorld";
    string t;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;   // Convert to lowercase
}
