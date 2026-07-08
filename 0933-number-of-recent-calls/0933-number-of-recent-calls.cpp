#include <bits/stdc++.h>
using namespace std;
class RecentCounter {
    queue<int> q;
    // This problem needs memory across function calls, so we store the queue as a class data member
public:
    // constructor -> runs automatically when object is created -> Used to set up the object initially
    RecentCounter() {
        // Nothing special to initialize manually
        // Because queue<int> q; data member automatically starts as an empty queue
        // So this means -> When RecentCounter object is created, do nothing extra. The queue is already empty by default

        // If needed, we could write inside contsructor too
        // jaise data member hota int age;
        // phir constructor ke andar likh dete age = 0;
        // to constructor initializes age
        // But in RecentCounter -> queue already initializs itself empty
        // So no need
    }
    // But an empty costructor is still given because the general design format is:
    // . Create object
    // . Call methods multiple times
    // . Object remembers state
    // Sometimes constructor gets input -> There, it may initialize values, but here, no input is needed, so constructor is empty 
    // Still LeetCode includes it because object creation must happen

    int ping(int t) {
        // Step 1. Add current ping time
        q.push(t);

        // Step 2. Remove pings older than t - 3000
        while(q.front() < t - 3000){
            q.pop();
        }

        // Step 3. Remaining pings are recent 
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/*

This is a design/class-based LeetCode problem, where LeetCode is calling the function mulitple times

Requests/pings are received at different times
eg. ping(1) -> Range = [-2999, 1] -> return 1;
    ping(100) -> Range = [-2900, 100] -> return 2;
    ping(3001) -> Range = [1, 3001] -> return 3;
    ping(3002) -> Range = [2, 3002] -> return 3
For every ping(t), we need to answer, "How many pings happened in the last 3000 milliseconds, including current time"
So for current time t, valid pings are in the range [t - 3000, t]
Anything smaller than t - 3000 is 'too old', and should not be counted

> Why queue?
Because pings come in increasing time order. Oldest ping is always at the front
To jab ek ping old ho jaa rahi hai(pichle 3000 millisecond se pehle ki) -> wo front me hai -> usko remove kar denge

Har new ping(t) ke liye, t queue me jodenge, uske according t - 3000 se kam wale ping ko remove karte jayenge, jab tak ki range me na aa jaye, queue size return kar denge

Now,
> RecentCounter(){}

RecentCounter obj; // Object created, constructor called here 

LeetCode is testing an object that remembers data between calls
Same object is used again and again
So the queue must remember previous pings

obj.ping(1);
obj.ping(100);
obj.ping(3001);
obj.ping(3002);

So your class needs to 'remember old ping times' between function calls

> Why queue<int> 1; outside ping()
That is why the queue should be a "DATA MEMBER" of the class, not a local variable inside "int ping"
So it stays alive as long as the object exists
RecentCounter obj; -> obj has its own queue inside it
So when obj.ping(1) -> Queue stores 1
        obj.ping(100) -> same queue still remembers 1 and then also stores 100

agar ping ke andar queue banayi hoti, to har baar ek naya empty queue banta aur purani pings forgot ho jati
Function end hota aur queue destroy ho jati

Now, 
> why while, not if
- if removes at most one old ping
- par kabhi kabhi ek se zyada ping old hongi, joki out of range hain
- eg. ping(1)
      ping(20)
      ping(30)
      ping(7000)

to jab tak, t - 3000 se kam rahega front element, use pop karte raho

> we are always doing q.push(t) and t < t - 3000 is impossible
  So queue empty to nahi hogi

phir bhi while(!q.empty() && q.front() < t - 3000) likhna behtar rehta kyunki empty queue me front() call karna is not safe

TC -> O(k) (Worst case -> if it pops many old elements) But across many calls, each ping is pushed once and popped once -> So, amortized time per call -> O(1)
SC -> O(w) (w is number of pings in current 3000ms window)
      O(n) (Worst case -> if many pings are within the window) (where n is number of calls so far)

*/