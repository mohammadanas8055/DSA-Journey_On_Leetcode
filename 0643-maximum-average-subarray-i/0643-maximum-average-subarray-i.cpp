class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double maxSum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == k){
                sum = sum - nums[i - k] + nums[i];
                maxSum = max(maxSum, sum);
                continue;
            }
            sum += nums[i];
            maxSum = sum; 
            count++;
        }
        return maxSum / k;
    }
};