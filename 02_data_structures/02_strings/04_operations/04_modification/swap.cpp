#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Galaxy";
    string t = "World";

    s.swap(t); // exchange contents
    
    cout << "s: " << s << endl; 
    cout << "t: " << t << endl; 
}
