class MinStack {
public:
    stack<int> out, in;
    int Min = INT_MAX;
    MinStack() {

    }
    void push(int val) {
        if (in.empty() || in.top() >= val) {
            in.push(val);
        }
        // if (Min >= val) {
        //     Min = val;
        //     cout << Min << " ";
        //     in.push(val);
        // }
        out.push(val);
    }
    void pop() {
        if (!in.empty() && in.top() == out.top()) { 
            in.pop();
            // Min = in.top();
        }
        out.pop();
    }
    int top() {
        return out.top();
    }
    int getMin() {
        return in.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
