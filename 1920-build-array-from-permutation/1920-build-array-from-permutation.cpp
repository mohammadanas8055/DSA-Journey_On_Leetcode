class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            ans[pos] = nums[temp];
            pos++;
        }
        return ans;
    }
};