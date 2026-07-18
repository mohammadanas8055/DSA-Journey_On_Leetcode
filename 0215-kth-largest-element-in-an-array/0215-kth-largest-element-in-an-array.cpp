class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> kElement;
        for(int i = 0; i < nums.size(); i++){
            kElement.push(nums[i]);
        }
        for(int i = 0; i < nums.size() - k; i++){
            kElement.pop();
        }
        return kElement.top();
    }
};