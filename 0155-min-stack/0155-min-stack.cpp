class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int val) {
        if (st.empty()){
            st.push(val);
            mini=val;
        }
        else if (val>=mini) st.push(val);
        else{
            st.push(2LL*val-mini);
            mini=val;
        }
    }
    
    void pop() {
        if (!st.empty()){
            if (st.top()<mini){
                int topValue=2LL*mini-st.top();
                mini=topValue;
            }
            st.pop();
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        if (st.top()<mini){
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return st.empty() ? -1 : mini;
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