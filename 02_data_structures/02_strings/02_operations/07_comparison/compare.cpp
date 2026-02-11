#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";

    // Using compare()
    int result = s1.compare(s2);
    if (result == 0) 
    cout << "s1 and s2 are equal" << endl;
    else if (result < 0) 
    cout << "s1 comes before s2" << endl;
    else 
    cout << "s1 comes after s2" << endl;

    return 0;
}
