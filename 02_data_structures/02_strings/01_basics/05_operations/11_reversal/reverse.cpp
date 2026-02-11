#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "HelloWorld";

    // Using reverse algorithm
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;

    return 0;
}
