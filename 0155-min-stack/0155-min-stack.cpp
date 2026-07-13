class MinStack {
public:
    stack<int> st; // Main stack- stores all values normally
    stack<int> min_st; // Helper stack- stores minimums at each state
    MinStack() {
        // Constructor- nothing to initialize
        // Both stacks are empty by default
    }
    
    void push(int value) {
        st.push(value); // Always push into main stack

        if(min_st.empty()){
            min_st.push(value);
        } // First element to current minimum rahega hi 
        else if(min_st.top() >= value){ // In case of duplicate minimum, dono baar push karna zaroori hai, warna minimum bigad jayega
        // eg, 5, 3, 2, 2
        //     min stack = 5, 3, 2( if only > used)
        //     ab agar pop kara
        // to 5, 3, 2
        // par minimum -> 5, 3 (Minimum lost)
            min_st.push(value);
        }
    }
    
    void pop() {
        if(min_st.top() == st.top()){ // pop from min_st only when jo element main stack se remove ho raha ho wo actually current minimum ho
            min_st.pop();
        }
        st.pop(); // This should come after popping element from min_st and done always
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        // Using a loop for getting minimum -> O(n) TC 
        // Par hame O(1) TC chahiye har function ke liye
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

/*

Normal stack values store karega, aur second stack har step ka minimum store karega. Jab bhi new value current minimum se chhoti ya equal ho, usse min stack me bhi push karenge. Pop karte waqt agar popped value current minimum ke equal hai, to min stack se bhi pop karenge.

TC -> O(1) in all functions, push(), pop(), top() and getMin()
SC -> O(n)
*/