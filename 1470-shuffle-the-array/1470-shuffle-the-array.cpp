class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(nums.size()); 
        // Final answer array banayi
        // nums.size() = 2 * n, so result ka size bhi utna hi hoga

        for(int i = 0; i < n; i++){
            // Loop sirf na times chalega
            // Kyunki total n pairs hain: (x1,y1), (x2,y2), (x3,y3)....(xn,yn)

            result[2 * i] = nums[i]; 
            // x wala(first half ka) element hamesha even index pe aayega

            result[2 * i + 1] = nums[n + i]; 
            // y wala(Second half ka) element hamesha odd index pe aayega
            // Why n+i -> second half index n se start hota hai 
        }
        // There are n pairs and i am placing two elements(one pair) for each iteration
        // That's why loop n times(n pairs getting placed)
        return result;
        // Shuffled array return kar di
    }
};

/*

TC -> O(2n) -> O(n) | SC -> O(2n) -> O(n)

*/

