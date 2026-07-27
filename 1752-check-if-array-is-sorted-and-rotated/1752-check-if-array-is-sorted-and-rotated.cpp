class Solution {
public:
    bool check(vector<int>& nums) {
        int decreaseCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[(i + 1) % nums.size()] ){
                decreaseCount++;
            }
        }
        if(decreaseCount > 1){
            return false;
        }
        return true;
    }
};