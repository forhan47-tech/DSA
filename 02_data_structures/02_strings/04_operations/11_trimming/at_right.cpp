#include <iostream>
#include <string>
using namespace std;

string trimRight(const string& s) {
    size_t end = s.find_last_not_of(" \t\n\r");
    if (end == string::npos) return ""; // all spaces
    return s.substr(0, end + 1);
}

int main() {
    string s = "   Hello World   ";
    cout << "Right-trimmed: '" << trimRight(s) << "'" << endl;
    return 0;
}
