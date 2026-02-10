#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1("HelloWorld");
    string s2(s1.begin(), s1.begin() + 5); // "Hello"
    cout << s2 << endl;
    return 0;
}
