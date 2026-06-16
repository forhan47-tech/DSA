#include <iostream>
#include <string>
using namespace std;

string trimLeft(const string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == string::npos) return ""; // all spaces
    return s.substr(start);
}

int main() {
    string s = "   Hello World   ";
    cout << "Left-trimmed: '" << trimLeft(s) << "'" << endl;
    return 0;
}
