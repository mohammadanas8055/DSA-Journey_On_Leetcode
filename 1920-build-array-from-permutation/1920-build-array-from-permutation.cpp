class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            ans[i] = nums[temp];
        }
        return ans;
    }
};