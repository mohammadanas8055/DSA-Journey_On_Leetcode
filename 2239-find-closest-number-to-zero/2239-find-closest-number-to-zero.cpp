class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = INT_MAX;
        // closest ko INT_MAX se initialize kiya
        // Kyunki hame 0 se sabse pass(minimum distance) wala number chahiye
        // Starting with maximum possible integer ensures ki pehla element
        // hamesha closest update kar dega(max element is 10^5)

        for(int i = 0; i < nums.size(); i++){

            // Case 1: Distance match ho gayi(Tie consition)
            // Example: closest = -2; nums[i] = 2
            // abs(-2) == abs(2) -> Both are 2 units away from 0
            if(abs(closest) == abs(nums[i])){
                closest = max(closest, nums[i]);
                // Problem constraint: "If there are multiple answers, return the number with the largest value"
                // max() ensures ki negative aur positive me se positive(larger number) retain ho
                // Example: max(-2,2) = 2
            }

            // Case 2: Strictly closer number mila
            else if(abs(closest) > abs(nums[i])){
                closest = nums[i];
                // Current element 0 ke zyada paas hai compared to previous closest
                // Directly update closes with nums[i](With sign)
            }
        }
        return closest;
        // Final 0 ke closest element return kar diya
    }
};

/*

Problem asks two things:
1. 0 ke sabse paas wala number (minimum absolute distance)
2. Tie-breaker: Agar do numbers ki distance 0 se same ho(jaise 2 and -2), to LARGER VALUE(positive value) choose karni hai

abs(closest) > abs(nums[i]) -> strictly closer number mila, directly update closest = nums[i]
abs(closest) == abs(nums[i]) -> distance barabr hai, to max(closest, nums[i]) positive/larger value pick kar leta hai automatically

TC -> O(n) | SC -> O(1)

*/