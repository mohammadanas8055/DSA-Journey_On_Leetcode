class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // Ye min-heap hai
                                                                // Isme hamesha current top k largest elements store karenge
                                                                // Min-heap isliye, taaki taaki un k elements me sabse chota element top par rahe
                                                                // Aur wahi kth largest hoga

        for(int i = 0; i < nums.size(); i++){
            if(minHeap.size() < k){ // Jab tak heap me k elements nahi aayen, tab tak directly push karte jao
                minHeap.push(nums[i]);
            }
            else if(nums[i] > minHeap.top()){ // Heap me already k elements hain
                                              // current element ko compare karo
                                              // suppose current number chota hai current heap ke dono elements se
                                              // to usko push karke phir se pop hi karna hai
                                              // uske bajaye agar wo element bada ho to abhi ke minimum se
                                              // tabhi heap se minimum ko hatao aur current jo usse bada wala element hai wo push kar do
                minHeap.pop();
                minHeap.push(nums[i]);
            } 
            else{ // Matlab current element chota tha, use add karne ki zaroorat hi nahi hai
                continue;
            }
        }
        return minHeap.top(); // End me heap me exactly k largest elements bachenge
                              // Unme sabse chota element top par hoga
                              // Aur wahi overall kth largest answer hai
    }
};

/*

Agar saare element ko push karoge to time complexity O(nlogn) aur SC O(n) ho jayegi 
To saare element store karne ke bajaye sirk "k largest elements seen so far" store karen
To size of min-heap = k -> operations cost = logk
smallest among those sits on top
aakhir me top = kth largest

Why min-heap and not max-heap for size k?
Because if heap stores the k largest elements:
the smallest among those k is exactly the kth largest overall

top of min-heap = kth largest

TC -> O(nlogk) -> (Processing all n elements once, for each element, pop/push on heap of size at most k) -> (Each such heap operation costs O(logk) | SC -> O(k) -> (Heap never stores more than k elements)

You optimize by ensuring:
heap never stores more than k elements

There is a more advanced selection algorithm known as Quickselect which takes average TC -> O(n) and SC -> O(1) extra

Core idea in one line:
Min-heap always stores the current k largest elements seen so far
And among those k elements:

top = smallest among them = kth largest overall
That is why minHeap.top() is the answer at the end.

Agar current number minHeap.top() se chhota ya equal hai,
to use ignore bhi kar sakte hain,
kyunki wo top k largest me aa hi nahi sakta.

*/