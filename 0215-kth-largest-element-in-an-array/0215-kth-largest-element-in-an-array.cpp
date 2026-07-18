class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> copy(nums.begin(), nums.end());
        while(k != 1){
            copy.pop();
            k--;
        }
        return copy.top();
    }
};