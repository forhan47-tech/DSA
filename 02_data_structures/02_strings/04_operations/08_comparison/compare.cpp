#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Apple";
    string t = "Banana";

    int res = s.compare(t);   // using compare() 

    if(res < 0 || res > 0) 
        cout << "Not Equal" << endl;

    if(res == 0) 
        cout << "Equal" << endl;

}
