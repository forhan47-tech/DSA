#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
    Node* head;  // top of stack
    int count;

public:
    Stack() {
        head = nullptr;
        count = 0;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void pop() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    int top() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // sentinel value
        }
        return head->data;
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }

    ~Stack() {
        clear();
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;   // 30
    cout << "Size: " << st.size() << endl;        // 3

    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20

    st.clear();
    cout << "Size after clear: " << st.size() << endl; // 0
}
