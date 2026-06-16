#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorldHello";

    size_t first = s.find("Hello");
    if(first != string::npos) cout << first << endl; // Find first occurrence

    size_t last = s.rfind("Hello");
    if(last != string::npos) cout << last << endl; // Find last occurrence
}
