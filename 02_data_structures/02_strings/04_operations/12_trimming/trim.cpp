#include <iostream>
#include <string>
using namespace std;

string ltrim(const string& s, const string& chars = " \t\n\r") {
    size_t start = s.find_first_not_of(chars);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string& s, const string& chars = " \t\n\r") {
    size_t end = s.find_last_not_of(chars);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string& s, const string& chars = " \t\n\r") {
    return rtrim(ltrim(s, chars), chars);
}

int main() {
    string text = "   Hello World   ";
    cout << "Trimmed:  [" << trim(text) << "]\n";
}
