class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(min_st.empty()){
            min_st.push(value);
        }
        else{
            if(value <= min_st.top()){
                min_st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.top() == min_st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */