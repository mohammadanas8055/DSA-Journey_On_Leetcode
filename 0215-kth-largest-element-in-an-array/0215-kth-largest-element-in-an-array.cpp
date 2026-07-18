class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> copy;
        for(int i = 0; i < nums.size(); i++){
            if(copy.size() < k){
                copy.push(nums[i]);
            }
            else if(nums[i] > copy.top()){
                copy.pop();
                copy.push(nums[i]);
            }
            else{
                continue;
            }
        }
        return copy.top();
    }
};