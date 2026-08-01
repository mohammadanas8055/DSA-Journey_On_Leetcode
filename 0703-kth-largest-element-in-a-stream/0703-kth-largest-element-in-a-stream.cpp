class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    // Min-heap use kar rahe hain
    // Heap me hamesha current K largest elements store karenge
    // In K elements me sabse chhota top par hoga
    // Aur wahi overall Kth largest answer hoga

    int K;
    // K ko class member me store karna zaroori hai
    // Kyunki add() function ke time bhi hame ye value chahiye
    // Constructor ka local parameter later survive nahi karega

    KthLargest(int k, vector<int>& nums) {
        K = k;
        // So that object ke lifetime me K stored rahe, ab add() me K use hoga
        // Without this, add() ko pata hi nahi chalega heap ka maximum size kya rakhna hai

        for(int i = 0; i < nums.size(); i++){
            if(pq.size() == k){
                // Heap already K elements se full hai
                // Ab har naya number directly nahi rakh sakte
                // Pehle check karna hoga ki kya ye current Kth largest se bada hai 

                if(nums[i] > pq.top()){
                    // agar current number top se bada hai
                    // to ye current top-K set me jagah deserve karta hai

                    pq.pop();
                    // Current Kth largest(smallest among top K) ko hata diya

                    pq.push(nums[i]);
                    // Naya better candidate heap me daal diya    
                }
                // Agar nums[i] <= pq.top() hai
                // to current top-K largest set par koi effect nahi padega
                // Isiliye use ignore kar denge
            }
            else{
                pq.push(nums[i]);
                // Heap abhi K se chhoti hai
                // Isliye initial filling phase me simply push karte jao
            }
        }
    }
    
    int add(int val) {
        if(pq.size() == K){
            // Heap already K elements hold kar rahi hai
            // Ab dekhna hai kya new val current K largest me aane layak hai

            if(val > pq.top()){
                pq.pop();
                // Current Kth largest ko hata diya

                pq.push(val);
                // Naya larger value heap me daal diya 
            }
            // Agar val top se chhota ya equal hai
            // to wo top-K largest me place nahi bana sakta 
            // Isliye ignore
        }
        else{
            pq.push(val);
            // Agar heap size K se chhoti hai(in case array me k elements bhi nahi the)
            // to bina compare kiye current value add kar do
        }
        return pq.top();
        // Heap me current K largest elements hain
        // Unme sabse chhota hi overall Kth largest hai
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/*

We do not care about all numbers
We care only about the K largest numbers seen so far
Un K largest numbers me jo sabse chhota hoga, wahi kth largest hoga
Isliya min-heap of size k

Har baar add() call par start se answer dobara nahi nikaalna padega

TC -> Constructor -> O(nlogk) (n initial elementd, each useful heap operation on size k heap)
   -> add() -> O(logk) (At most one compare, one pop, one push)
SC -> O(k) (Heap stores at most k elements)

*/