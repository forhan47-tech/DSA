#include <iostream>
#include <string>
using namespace std;

string ltrim(const string& s) {
    size_t start = s.find_first_not_of(" \t\n\r"); 
    return (start == string::npos) ? "" : s.substr(start);
}

int main() {
    string text = "   Hello World   ";
    cout << "Left Trim:    [" << ltrim(text) << "]\n";
}
