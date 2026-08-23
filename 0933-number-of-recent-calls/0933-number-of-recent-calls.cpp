class RecentCounter {
public:
    queue<int> recent;
    // Queue me ham sabhi valid ping times store karenge

    // Queue kyun(not stack ya vector)?
    // - Purane pings sirf front se remove hote hain(FIFO)
    // - Naye pings back me add hote hain
    // - Ye exactly queue ka behaviour hai - perfect fit

    // Alternative: deque bhi kaam karta, but simple queue enough hai kyunki 
    // hame dono ends se access chahiye - front(peek/pop) aur back(push)

    RecentCounter() {
        // Constructor - kuch initialize nahi karna 
        // Queue by default empty banti hai
    }
    
    int ping(int t) {
        recent.push(t);
        // Current ping ko queue ke back me add kar diya
        // Ye hamesha valid hai(current time to naya hai hi)

        while(recent.front() < t - 3000){
            recent.pop();
            // Front wala ping ab window ke bahar hai(bahut purana)

            // < isliye use kiya (not <=)
            // Window inclusive hai [t - 3000, t]
            // Yani ping at exactly (t - 3000) still counts
            // Sirf (t - 3001) ar usse purane ping invalid hain

            // Loop ab tak chalega jab tak front pe valid ping na aa jaye
            // Aur wahi valid pings me bachenge 
        }
        return recent.size();
        // Queue size = current window ke andar total valid pings ka count 
        // Yahi hamara answer haii
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/*

Har ping(t) call me batana hai ki last 3000 ms me kitne pings hue hain(including current)
Window: [t, t - 3000]

Queue is perfect because FIFO -> sabse purana ping front pe, sabse naya back pe
Purane pings(window ke bahar) sirf front se hi remove hone chahiye
Naye pings sirf back pe add hone chahiye

TC -> ping(): Amortized O(1)
     Kabhi kabhi ek ping() call me multiple pops ho sakte hain(agar bahut purane pings queue me pade the). Us moment pe wo call O(k) hoti hai (k = purane pings ka count)
     Lekin overall:
     . Har ping queue me exactly ek baar push hota hai(jab ping call hoti hai)
     . Har ping queue se exactly ek baar pop hota hai(jab window ke bahar chala jaata hai)
     So har ping ki total lifetime cose = 2 operations(constant)
     Agar ham n pings karte hain:
     . Total ops = 2n
     . Per ping avg = O(1) amortized

SC -> O(W) (W = window size me maximum kitne pings ho sakte hain)

*/