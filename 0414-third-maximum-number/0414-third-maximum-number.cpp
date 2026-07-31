class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = -3000000000LL;
        long long second = -3000000000LL;
        long long third= -3000000000LL;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == first || nums[i] == second || nums[i] == third){
                continue;
            }
            if(nums[i] > first){
                third = second;
                second = first ;
                first = nums[i];
            }
            else if(nums[i] > second){
                third = second;
                second = nums[i];
            }
            else if(nums[i] > third){
                third = nums[i];
            }
        }
        if(third != -3000000000LL){
            return third;
        }
        return first;
    }
};