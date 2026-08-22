class MyQueue {
public:
    stack<int> st;
    // Input stack - jab bhi push() call hoti hai, yahan element aata hai
    // Ye stack "newest on top" order me elements rakhta hai
    // Yani agar push(1), push(2), push(3) kiya, to st: [1,2,3] with top = 3

    stack<int> q;
    // Output stack - jab bhi pop()/peek() call hoti hai, yahan se element milta hai
    // Ye stack "oldest on top" order me elements rakhta hai(FIFO ready)
    // Yani agar st: [1,2,3] tha aur transfer kiya, to q: [3,2,1] with top = 1

    MyQueue() {
        // Constructor - kuch initialize karne ki zaroorat nahi 
        // C++ me dono stacks default empty bante hain
    }
    
    void push(int x) {
        st.push(x);
        // naya element hamesha input stack me hi jaata hai
        // Isse push() operation hamesha O(1) hoti hai

        // Yahan koi transfer nahi kar rahe kyunki:
        // 1. Transfer expensive hai(n operations)
        // 2. Zaroori nahi ki abhi transfer karein - jab pop/peek chahiye tabhi karenge
        // 3. Lazy transfer amortized O(1) deti hai overall
    }
    
    int pop() {
        if(q.empty()){
            // Sirf tabhi transfer karo jab output stack khali ho 

            // Ye critical hai: agar q me abhi bhi elements hain,
            // to unhe pehle serve karo(unka order pehle se FIFO ready hai)

            // Warna aage wale elements pehle nikal jayenge(LIFO ho jayega)

            while(!st.empty()){
                q.push(st.top());
                st.pop();
                // st ka top pop karke q me push kar rahe hain 
                // Isse order reverse ho jaata hai

                // Example: st = [1,2,3] (top = 3)
                // Transfer ke baad q = [3,2,1] (top = 1)
                // Ab q.top() = 1 = jo pehle push hua tha = FIFO front!
            }
        }
        int temp = q.top();
        q.pop();
        // ab q ka top hi FIFO ka front hai 
        // Isliye directly pop kar sakte hain

        // Note: q ko wapas st me push karne ki zaroorat NAHI hai
        // Baaki elements q me hi rehne do - agla pop unhi se seedhe serve hoga

        return temp;
    }
    
    int peek() {
        if(q.empty()){
            // Same logic as pop() - transfer sirf jab zaroori ho
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }
        }
        return q.top();
        // Peek me sirf top dekhna hai, pop nahi karna 
    }
    
    bool empty() {
        return q.empty() && st.empty();
        // Queue tabhi empty hai jab dono stacks empty hon

        // && zaroori hai ( || galat hoga) kyunki 
        // - Agar sirf st empty hai, q me abhi bhi elements ho sakte hain(aur wo FIFO front hain)
        // - Agar sirf q empty hai, st me elements ho sakte hain(wo transfer hoke aayenge)

        // Dono khali hone par hi kuch nahi bacha
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
push -> O(1) always 
pop -> O(n) (Worst single ek call me O(n))
    -> But overall/amortized O(1) (Overall n operations me O(n) total)
       Because every element goes into input once, moves to output once, pops once
       It doesn't get transferred again and again forever. So total work spread over many operations is linear, hence amortized O(1)
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

Har element apni lifetime me exactly 2 baar move hota hai:
1. push() -> st me enter
2. Transfer time -> st se pop, q me push(2 ops)
3. pop() -> q se nikalta hai
Total ops per element = 4(constant)

Agar ham n push and n pop karte hain
. Total ops = 4n
. Per operation avg = 4n / 2n = O(1) amortized

Kabhi kabhi ek pop() bhaari lagti hai (jab transfer trigger hota hai — O(n) us moment pe), lekin agle n-1 pops O(1) me hote hain. Average out ho jaata hai.

Lazy transfer pattern 

“Yes, using two stacks we can implement queue with amortized O(1) operations.
Push goes into input stack.
Pop/peek use output stack.
If output stack is empty, we transfer all elements from input to output once.
Since each element is pushed once, transferred once, and popped once, total work for n operations is O(n), so amortized time per operation is O(1).”

*/