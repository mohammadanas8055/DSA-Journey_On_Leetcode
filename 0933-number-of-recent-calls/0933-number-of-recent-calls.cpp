class RecentCounter {
public:
    queue<int> recent;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        recent.push(t);
        while(recent.front() < t - 3000){
            recent.pop();
        }
        return recent.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */