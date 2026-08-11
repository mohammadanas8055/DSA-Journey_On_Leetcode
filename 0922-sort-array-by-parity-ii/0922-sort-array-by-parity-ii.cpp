class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0;
        int odd = 1;
        while(even <= nums.size() - 1 && odd <= nums.size() - 1){
            if(nums[even] % 2 == 0){
                even += 2;
                continue;
            }
            if(nums[odd] % 2 != 0){
                odd += 2;
                continue;
            }
            swap(nums[odd], nums[even]);
            odd += 2;
            even += 2;
        }
        return nums;
    }
};