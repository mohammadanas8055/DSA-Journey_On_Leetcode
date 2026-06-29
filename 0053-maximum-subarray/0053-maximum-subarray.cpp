class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumRightNow = 0; // sare elements ko add karna hai, to initialize karenge zero se
        int maxSum = nums[0]; // compare karne ke liye pehla element
        for(int i = 0; i < nums.size(); i++){
            sumRightNow = sumRightNow + nums[i];
            if(sumRightNow > maxSum){
                maxSum = sumRightNow;
            }
            if(sumRightNow < 0){
                sumRightNow = 0; // Key Reset -> Negative aaya hai agar sumSoFar, to wo aage Madad to nahi hi karega na, to usko zero kar do, aur agle element se naya sumSoFar track karo

            }
        }
        return maxSum;
    }
};

/// KADANE'S ALGORITHM - Maximum Subarray Sum

// Pattern: Track running sum + max sum
// Key insight: Reset running sum to 0 when it goes negative
//              (negative running sum can only DECREASE future sums)

// Time: O(n) | Space: O(1)

// Used in:
// - Maximum Subarray
// - Best Time to Buy/Sell Stock (variation)
// - Many "find max contiguous" problems

// By starting maxSum = nums[0], we ensure even all-negative arrays return the correct max element.
// and not starting from maxSum = 0;
