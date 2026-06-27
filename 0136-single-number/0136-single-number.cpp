class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result = result ^ nums[i];
        }
        return result;
    }
};

// XOR is commutative, order doesn't matter
// Also the property that XOR with 0 = original number 
// so initialise XOR with 0 and XOR all the elements together 
// anything XOR with itself = 0
// finally left with the single element
