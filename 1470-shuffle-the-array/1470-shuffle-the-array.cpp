class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2 * n);
        int pos = 0;
        int i = 0;
        int j = n;
        while(j < 2 * n){
            result[pos] = nums[i];
            i++;
            pos++;
            result[pos] = nums[j];
            j++;
            pos++;
        }
        return result;
    }
};