class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};

/*

Time complexity -> O(n) and Space complexity -> O(1) (ignoring returned input vector itself)

*/