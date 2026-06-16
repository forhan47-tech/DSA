#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "Apple";
    string b = "Banana";

    if(a < b || a > b) 
        cout << "Not Equal" << endl;    // using operator<

    if (a == b) 
        cout << "Equal" << endl;
}
