class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(num < 0){
                num *= -1;
            }
            int index = num - 1;
            if(nums[index] < 0){
                continue;
            }
            nums[index] *= -1;
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};