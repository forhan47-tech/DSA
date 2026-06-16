#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    string t(s, 2, 5);   // start at index 2, length 5
    string u(s, 5);   // start at index 5
    
    cout << t << endl;
    cout << u << endl;
}
