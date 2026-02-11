#include <iostream>
#include <string>
using namespace std;

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");

    if (start == string::npos) return ""; // all spaces
    return s.substr(start, end - start + 1);
}

int main() {
    string s = "   Hello World   ";
    cout << "Trimmed: '" << trim(s) << "'" << endl;
    return 0;
}
