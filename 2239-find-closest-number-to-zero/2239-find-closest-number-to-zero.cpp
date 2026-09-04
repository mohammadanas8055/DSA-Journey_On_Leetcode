class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(abs(closest) == abs(nums[i])){
                closest = max(closest, nums[i]);
            }
            else if(abs(closest) > abs(nums[i])){
                closest = nums[i];
            }
        }
        return closest;
    }
};