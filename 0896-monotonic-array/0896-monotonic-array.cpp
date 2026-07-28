class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] <= nums[i + 1]){
                a++;
            }
            if(nums[i] >= nums[i + 1]){
                b++;
            }
        }
        if(a == nums.size() - 1 || b == nums.size() - 1){
            return true;
        }
        return false;
    }
};