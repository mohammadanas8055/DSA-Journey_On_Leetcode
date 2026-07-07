class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(nums.size(), 0);
        int position = 0;
        for(int i = 0; i < n; i++){
            result[position] = nums[i];
            position++;
            result[position] = nums[n + i];
            position++;
        }
        return result;
    }
};