class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        int position = 0;
        k = k % n;
        for(int i = n - k; i < n; i++){
            ans[position] = nums[i];
            position++;
        }        
        for(int i = 0; i < n - k; i++){
            ans[position] = nums[i];
            position++;
        }
        nums = ans;
    }
};