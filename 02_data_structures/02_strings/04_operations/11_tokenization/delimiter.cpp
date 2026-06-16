#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string text = "apple,banana,orange";
    stringstream ss(text);
    string tok;

    while (getline(ss, tok, ',')) {
        cout << tok << endl;
    }
}
