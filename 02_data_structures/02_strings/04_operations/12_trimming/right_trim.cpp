#include <iostream>
#include <string>
using namespace std;

string rtrim(const string& s) {
    size_t end = s.find_last_not_of(" \t\n\r"); 
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

int main() {
    string text = "   Hello World   ";
    cout << "Right Trim:    [" << rtrim(text) << "]\n";
}
