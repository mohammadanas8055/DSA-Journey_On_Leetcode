class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0; // next even index for positives(0,2,4,6..)
        int j = 1; // next odd indecx for negatives(1,3,5...)
        int n = nums.size();
        vector<int> result(n); // pre-sized(no push_back needed)
        
        // while(i < n && j < n){
        //     while(nums[i] < 0){
        //         i++;
        //     }
        //     result.push_back(nums[i]);
        //     while(nums[j] > 0){
        //         j++;
        //     }
        //     result.push_back(nums[j]);
        //     i++;
        //     j++;
        // }

        // Inner loop can be UB, here not, because we hve been given equal number of even and odd integers
        // But if all are negative/positive -> undefined behaviour

        // Cleaner approach: Instead of finding positive and then pushing back(which also could give UB if all negatives/positives are there), just place at the right place

        // single pass through original array - order automatically preserved
        for(int k = 0; k < n; k++){
            if(nums[k] > 0){
                result[i] = nums[k]; // place positive at next even slot
                i += 2; // jump to next even index
            }
            else{
                result[j] = nums[k]; // place negative at next odd slot 
                j += 2; // jump to next odd index
            }
        }
        return result;
    }
};

/*

TC -> O(n) | SC -> O(n)

*/