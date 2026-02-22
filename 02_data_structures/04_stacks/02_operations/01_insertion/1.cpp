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

    bool full() {
        return top == cap-1;
    }

    void push(int val) { 
        if (full()) { 
            cout << "Stack Overflow\n"; 
            return; 
        } 

        arr[++top] = val; 
    }
};

int main() {
    Stack st(5);
}
