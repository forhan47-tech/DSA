#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";

    string t = s.substr(2, 6); // start at index 2, length 6
    cout << t << endl; 

    string u = s.substr(4);   // from index 4 to end
    cout << u << endl;
}
