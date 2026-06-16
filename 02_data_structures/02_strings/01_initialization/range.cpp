#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "HelloWorld";
    string t(s.begin(), s.begin()+4); 
    cout << t << endl; 
}
