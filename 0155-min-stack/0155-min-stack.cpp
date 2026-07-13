class MinStack {
public:
    //# Step 1: Initialize a single stack and a minimum tracker
    //! Safety Guard: We use long long to prevent Integer Overflow 
    //! during the 2 * x - mini calculation.
    stack<long long> st; 
    long long mini;      

    MinStack() {}
    
    void push(int val) {
        long long x = val;
        
        //* Case 1: First element pushed is always the starting minimum
        if (st.empty()) {
            st.push(x);
            mini = x;
        }
        //* Case 2: Value is larger, no change to the current minimum
        else if (x >= mini) {
            st.push(x);
        }
        //* Case 3: Value is smaller. Encrypt the entry and update minimum
        else {
            st.push(2 * x - mini); //* Encrypts previous minimum inside the value
            mini = x;              //* Update current minimum to the new value
        }
    }
    
    void pop() {
        if (st.empty()) return;

        long long top_val = st.top();
        st.pop();
        
        //* If top_val is less than mini, our encryption flag was popped!
        //* This means we must decrypt and restore the previous minimum.
        if (top_val < mini) {
            mini = 2 * mini - top_val; //* Decryption formula
        }
    }
    
    int top() {
        long long top_val = st.top();
        
        //* If top_val is encrypted (less than mini), the actual value is 'mini'
        if (top_val < mini) {
            return mini;
        }
        return top_val;
    }
    
    int getMin() {
        //* Returns the active minimum instantly
        return mini;
    }
};
/*
    💡 Complexity Analysis:
    - Time Complexity (TC): O(1) for all operations.
    - Auxiliary Space Complexity (SC): O(1) -> We use zero extra tracking stacks.
*/