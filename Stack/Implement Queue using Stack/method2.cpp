// TC: O(1)
// SC: O(1) {amortized}

class MyQueue {
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()) {
            int val = output.top();
            output.pop();
            return val;
        }
        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int val = output.top();
            output.pop();
            return val;
            
        } 
    }
    
    int peek() {
        if(!output.empty()) {
            return output.top();
        }
        else {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return output.top();
            
        } 
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
