class MyQueue {
public:
    stack<int> st1, st2;
    int front;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (st1.empty()) front = x;
        st1.push(x);    
    }
    
    int pop() { 
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int val = -1;
        if (!st2.empty()) {
            val = st2.top();
            st2.pop();
            if (!st2.empty()) front = st2.top();
        }
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return st1.empty();
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