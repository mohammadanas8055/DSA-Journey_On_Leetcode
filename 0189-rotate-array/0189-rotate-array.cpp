class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0;
        int j = nums.size() - 1;
        k = k % nums.size();
        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        int i2 = 0; 
        int j2 = k - 1;
        while(i2 < j2){
            swap(nums[i2], nums[j2]);
            i2++;
            j2--;
        }
        int i3 = k; 
        int j3 = nums.size() - 1;
        while(i3 < j3){
            swap(nums[i3], nums[j3]);
            i3++;
            j3--;
        }
    }
};