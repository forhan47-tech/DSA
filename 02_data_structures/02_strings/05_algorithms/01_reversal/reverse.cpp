#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";
    reverse(s.begin(), s.end());   // reverses in place
    cout << s << endl;
}
