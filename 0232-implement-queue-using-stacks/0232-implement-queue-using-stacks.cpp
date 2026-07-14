class MyQueue {
public:
    stack<int> st; // input stack - naye elements yahan aayenge
    stack<int> q; // output stack - purane elements yahan se niklenge

    MyQueue() {
        
    }

    void push(int x) {
        st.push(x);
        // new element always in input stack
        // rear me add hona = input ka top
    }
    
    int pop() {
        if(q.empty()){
            // output stack empty hai, yani purane elements available nahi hain
            // input se saare elements output me transfer kar lenge
            // transfer se order reverse hoga
            // aur sabse purana element output ke top pe aa jayega(FIFO)
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }
        }
        // ac output ka top = queue ka front(Sabse purana element)
        int front = q.top();
        q.pop();
        return front;
    }
    
    int peek() {
        if(q.empty()){
            // same transfer logic as pop
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }
        }
        return q.top();
    }
    
    bool empty() {
        if(st.empty() && q.empty()){
            // queue tabhi empty hai jab dono stacks empty hon
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

/*

We do NOT keep the queue perfectly arranged all the time 
Instead, input stack -> new elements yahan aayenge
         output stack -> front elements yahan se niklega

Old elements stay in output
new elements wait in input(jab tak output me khatam nahi ho raha)

Jab dono hi empty honge, tabhi koi bhi element nahi bacha hoga, tabhi queue is truly empty

TC 
push -> O(1)
pop -> O(n) (Worst single call: if transfer happens)
    -> But overall/amortized O(1)
       Because every element goes into input once, moves to output once, pops once
       It doesn't get transferred again and again forever]So total work spread over many operations is linear, hence amortized O(1)
peek -> same logic as pop 
     -> amortized O(1)
empty -> O(1)
SC -> O(n)

*/

/*

Amortized O(1) means:
. one operation may occasionally be expensive
. but across many operations, everage cost per operation is O(1)
  - 1 operation may take O(n)
  - but n total operations together take O(n)
  - hence average = O(1) per operation

eg.   
push(1)
push(2)
push(3)
pop()
pop()
pop()

Work done:
push 1 → O(1)
push 2 → O(1)
push 3 → O(1)
first pop:
transfer 3 elements → O(3)
pop 1
second pop → O(1)
third pop → O(1)
Total work:

O(1 + 1 + 1 + 3 + 1 + 1) = O(8) = O(n)
Not O(n²).

That is why it is amortized O(1).

“Yes, using two stacks we can implement queue with amortized O(1) operations.
Push goes into input stack.
Pop/peek use output stack.
If output stack is empty, we transfer all elements from input to output once.
Since each element is pushed once, transferred once, and popped once, total work for n operations is O(n), so amortized time per operation is O(1).”

*/