#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello, World!";

    s.erase(s.begin()+5); // remove single character at index 5
    cout << s << endl;

    s.erase(5, 6); // remove 6 characters starting at index 5
    cout << s << endl; 
}
