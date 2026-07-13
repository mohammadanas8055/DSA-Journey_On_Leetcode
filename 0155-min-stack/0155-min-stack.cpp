class MinStack {
public:
    stack<int> main_st;
    stack<int> min_st;
    MinStack() {
        
    }
    
    void push(int value) {
        main_st.push(value);
        if(min_st.empty() || value <= min_st.top()){
            min_st.push(value);
        }
    }
    
    void pop() {
        if(main_st.top() == min_st.top()){
            min_st.pop();
        }
        main_st.pop();
    }
    
    int top() {
        return main_st.top();
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