class MyQueue {
public:
    stack<int> st;
    stack<int> q;
    MyQueue() {
        
    }

    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(q.empty()){
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }
        }
        int front = q.top();
        q.pop();
        return front;
    }
    
    int peek() {
        if(q.empty()){
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }
        }
        return q.top();
    }
    
    bool empty() {
        if(st.empty() && q.empty()){
            return true;
        }
        return false;
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