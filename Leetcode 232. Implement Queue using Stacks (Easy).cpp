class MyQueue {
public:
   stack<int> in, out;
    MyQueue() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        in2out();
        int ret = out.top();
        out.pop();
        return ret;
    }
    
    int peek() {
        in2out();
        return out.top();
    }
    
    void in2out() {
        if (out.empty()) {
            while (!in.empty()) {
                int temp = in.top();
                in.pop();
                out.push(temp);
            }
        }
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
