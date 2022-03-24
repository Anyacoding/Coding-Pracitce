class MyStack {
public:
    queue<int> in;
    queue<int> out;
    MyStack() {

    }
    
    void push(int x) {
        in.push(x);
        while (!out.empty()) {
            in.push(out.front());
            out.pop();
        }
        swap(in, out);
    }
    
    int pop() {
        int temp = top();
        out.pop();
        return temp;
    }
    
    int top() {
        return out.front();
    }
    
    bool empty() {
        return out.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
