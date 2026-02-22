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

    bool full() {
        return top == cap-1;
    }
};

int main() {
    Stack st(5);
}
