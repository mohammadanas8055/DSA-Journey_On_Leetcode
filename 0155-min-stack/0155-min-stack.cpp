class MinStack {
public:
    stack<int> st;
    // Main stack- stores all values normally
    // Standard push/pop/top operations ke liye

    stack<int> min_st;
    // Auxiliary stack - sirf minimum values track karne ke liye 
    // har point pe iska top = main stack ka current minimum hoga

    // Ye 2-stack approach isliye use karte hain kyunki
    // getMin() ko O(1) me karna hai
    // Agar sirf ek stack hota, to har baar minimum dhundhne ke liye pura stack scan karna padta = O(n)

    MinStack() {
        // Constructor- nothing to initialize(dono stacks empty se start)
        // C++ me stacks are empty by default, so kuch initialize karne ki zaroorat nahi
    }
    
    void push(int value) {
        st.push(value);
        // Main stack me hamesha value push hoti hai

        if(min_st.empty()){
            min_st.push(value);
            // Agar min_st khali hai, to pehle element hi minimum hai
            // Directly push kar do
        }
        else{
            if(value <= min_st.top()){
                min_st.push(value);
                // <= isliye use kiya, sirf < nahi:

                // Agar value current minimum ke barabar hai, to bhi push karo
                // Warna future me pop karte samay min_st galat ho jayega
                
                // xample: push(3), push(3), phir pop()
                // Agar duplicate 3 ko min_st me nahi push kiya
                // to pop ke baa dmin_st.top() aur st.top() mismatch ho jayega
                // Aur min_st galti se pura empty ho jayega
            }
            // Agar value min_st.top() se badi hai, to kuch nahi karna
            // Current minimum change nahi hua
        }
    }
    
    void pop() {
        if(st.top() == min_st.top()){
            min_st.pop();
            // Agar jo element pop ho raha hai wo current minimum hai
            // to min_st se bhi hatana zaroori hai

            // Otherwise stale minimum reh jayega jo actually stack me hai hi nahi 

            // Ye check pehle karna zaroori hai, st.top() ke baad nahi
            // Warna st.top() galat value dega
        }
        st.pop();
        // Main stack se hamesha pop karo
    }
    
    int top() {
        return st.top();
        // Simple main stack ka top return kar diya
        // min_st ka isse koi lena-dena nahi 
    }
    
    int getMin() {
        return min_st.top();
        // Yahi is design ka main benefit hai:
        // O(1) me current minimum mil jaata hai
        // Kyunki min_st ka top hamesha current minimum hi hota hai
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

TC -> O(1) for all operations, push() -> (2 stack pushes), pop() -> (comparison +  2 pops), top() -> (1 stack top) and getMin() -> (1 stack top) | SC -> O(n) (Worst case dono stacks n element hold kar sakte hain, strictly decreasing sequence [5,4,3,2,1] -> har element min_st me bhi jayega)

Alternative approaches
1. Single stack with pair<int,int>
   Har element ke saath(value, current_min) store karo. Same complexity, different style

*/