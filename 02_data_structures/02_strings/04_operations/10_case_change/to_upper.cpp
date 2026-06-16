#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "HelloWorld";
    
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;   // Convert to uppercase
}
