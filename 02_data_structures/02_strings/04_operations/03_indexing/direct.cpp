#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    cout << s[0] << endl; // Access index -> 0

    s[1] = 'a';   // modify index 1 -> a
    cout << s << endl;      
}
