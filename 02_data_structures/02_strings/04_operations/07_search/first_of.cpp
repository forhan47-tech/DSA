#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcdefgabc";

    size_t first = s.find_first_of("cde");
    if(first != string::npos) cout << first << endl; // Find first of any

    size_t last = s.find_last_of("abc");
    if(last != string::npos) cout << last << endl; // Find last of any
}