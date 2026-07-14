class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size(); // Cleaner version(Fixed number of rotation) instead of i < q.size() (Ek baar push, ek baar pop, net size same hai, par doubt na ho)
        for(int i = 1; i < n; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() { 
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*

> We do NOT pop from the rear of the queue directly
Instead rearrange the queue so that most recent element comes to the front
Stack banane ke liye ye ensure karna hoga -> Stack ka top = queue ka front
Because queue me ham pop only front se kar sakte hain

- So using one-queue, costly push
to rear me new element push karne ke baad 
rotate karenge queue ko size - 1 times(purane elements ko front se nikaal kar rear me daalte rahenge)
taaki newly inserted element front pe aa jaye

Ab pop() se front pop() hoga joki top hoga stack ka 
top() ke liye front element return kar do
empty() ke liye -> queue empty hai ya nahi

# Stack behaviour is achieved by rotation after pushing

TC -> push() -> O(n)
      pop() -> O(1)
      top() -> O(1)
      empty() -> O(1)
SC -> O(n)

*/

/*

Two-queue methods:
1. Method 1: Costly push
   put new element in q2
   move all older elements of q1 into q2
   swap q1 and q2

class MyStack{
public:
    queue<int> q1, q2;

    MyStack(){
    }

    void push(int x){
        q2.push(x);
    
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    
        swap(q1, q2);
    }

    int pop(){
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

   TC 
   push   -> O(n)     
   pop    -> O(1)
   top    -> O(1)
   empty  -> O(1)
   SC     -> O(n)

2. Method 2: Costly pop
   push always into q1
   pop ke time first n-1 elements q1 -> q2 move karo
   last element remove karo
   swap queues

class MyStack(){
public:
    queue<int> q1, q2;

    MyStack(){
    }

    void push(int x){
        q1.push(x);
    }

    int pop(){
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }    

        int ans = q1.front();
        q1.pop();

        swap(q1, q2);
        return ans;
    }

    int top(){
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q2.push(q1.front()); // Preserve top element
        q1.pop();

        swap(q1, q2);
        return ans;
    
    }

    bool empty(){
        return q1.empty();
    }
};

   TC 
   push   -> O(1)
   pop    -> O(n)
   top    -> O(n)   // if done similarly
   empty  -> O(1)
   SC     -> O(n)

So which is better 

One-queue approach = pop(), top() fast chahiye
Two-queue costly push = same trade-off, but helper queue use karke concept more intuitive lage
Two-queue costly pop = jab many pushes hon, pop/top less hon

*/