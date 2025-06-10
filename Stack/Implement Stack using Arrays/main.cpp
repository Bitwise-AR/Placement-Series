#include <iostream>
using namespace std;

class Stack {
    public: 

    int idx = -1;
    int arr[5];

    void push(int num) {
        if(idx < 4) {
            idx += 1;
            arr[idx] = num;
        }
        else {
            cout << "Stack overflow!" << endl;
        }
    }

    void pop() {
        if(idx >= 0)
            idx -= 1;
        else
            cout << "Stack underflow" << endl;
    }

    int top() {
        if(idx >= 0) {
            return arr[idx];
        }
        else {
            cout<< "Stack is empty" << endl;
            return -1;
        }
    }

    bool empty() {
        return (idx == -1) ? true : false;
    }
};

int main() {
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.top() << endl;   // output:  5
    
    st.pop();
    
    cout << st.top() << endl;   // output:  4

    cout << st.empty() << endl; // output:  0 (false)
}

