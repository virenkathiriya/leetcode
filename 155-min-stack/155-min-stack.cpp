class MinStack {
public:
    stack<long long> s;
    long long el;
    MinStack() {
        
    }
    
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            el = x;
        } else {
            if (x < el) {
                s.push(2LL * x - el);
                el = x;
            } else {
                s.push(x);
            }
        }
    }
    
    void pop() {
        long long t = s.top();
        if (t < el) {
            el = 2LL * el - t;
        }
        s.pop();
    }
    
    int top() {
        if (s.top() < el) return el;
        return s.top();
    }
    
    int getMin() {
        return el;
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