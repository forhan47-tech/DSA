#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello World";
    const char* t = s.c_str(); // C-style string
    cout << t << endl; 
}
