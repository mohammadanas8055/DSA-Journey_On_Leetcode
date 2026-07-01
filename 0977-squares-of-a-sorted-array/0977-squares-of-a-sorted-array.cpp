class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        for(int k = 0; k < nums.size(); k++){
            nums[k] = nums[k] * nums[k];
        }
        int i = 0;
        int j = nums.size() - 1;
        int pos = nums.size() - 1;
        while(i <= j){
            if(nums[i] > nums[j]){
                result[pos] = nums[i];
                i++;
            }
            else{
                result[pos] = nums[j];
                j--;
            }
            pos--;
        }
        return result;
    }
};

// This works because nums was sorted

// Time Complexity -> O(n)
// Space complexity -> O(n)

// IMPROVEMENT:
// Square karke nums modify karne ki zaroorat nahi thi
// ya to absolute value ko compare karke result vectore me store karen
// ya directly square karke left aur right walon ko compare karke place kar den result vector