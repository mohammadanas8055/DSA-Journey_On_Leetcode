class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count == 0){
                majority = nums[i];
            }
            if(nums[i] == majority){
                count++;
            }
            else{
                count--;
            }
        }
        return majority;
    }
};