class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int leftProduct = 1;
        ans[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            leftProduct *= nums[i - 1];
            ans[i] = leftProduct;
        }
        int rightProduct = 1;
        for(int i = nums.size() - 2; i >=0; i--){
            rightProduct *= nums[i + 1];
            ans[i] = ans[i] * rightProduct;
        }
        return ans;
    }
};