#include <iostream>
using namespace std;

class Queue {
    int front = 0;
    int rear = 0;

    int cnt = 0, n = 5;
    int arr[5];

    public: 
    void push(int num) {
        if(cnt == n) {
            cout << "Queue is full!" << endl;
        } 
        else {
            arr[rear % n] = num;
            rear += 1;
            cnt += 1;
        }
    }

    void pop() {
        if(cnt == 0) {
            cout << "Queue is empty!" << endl;
        } 
        else {
            front += 1;
            cnt -= 1;
        }
    }

    int top() {
        if(cnt == 0) {
            cout << "Queue is empty!" << endl; 
            return -1;
        }
        return arr[front % n];
    }

    bool empty() {
        return (cnt == 0) ? true : false;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); // Queue full after this
    q.push(60); // Should show "Queue is full!"

    cout << "Top: " << q.top() << endl; // Should be 10

    q.pop();
    q.pop();

    cout << "Top after 2 pops: " << q.top() << endl; // Should be 30

    q.push(60);
    q.push(70); // Should wrap around and fill empty slots

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    q.pop(); // Should show "Queue is empty!"
}
