class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int intendedSum = 0;
        for(int i = 0; i <= n; i++){
            intendedSum += i;
        }
        return intendedSum - sum;
    }
};