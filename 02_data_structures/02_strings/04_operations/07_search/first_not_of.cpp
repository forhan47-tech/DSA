#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "aaaabxyz";

    size_t first = s.find_first_not_of("ab");
    if(first != string::npos) cout << first << endl; // Find not first of any

    size_t last = s.find_last_not_of("xyz");
    if(last != string::npos) cout << last << endl; // Find not last of any
}
