#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int cap;

public:
    Stack(int size) {
        cap = size;
        arr = new int[cap];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool empty() {
        return top == -1;
    }

    int peek() { 
        if (empty()) { 
            cout << "Stack is empty!\n"; 
            return -1; 
        } 
        return arr[top]; 
    }
};

int main() {
    Stack st(5);
}
