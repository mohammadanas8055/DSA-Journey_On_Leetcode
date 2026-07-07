class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(nums.size()); // or write 2 * n
        int position = 0;
        for(int i = 0; i < n; i++){
            result[position] = nums[i];
            position++;
            result[position] = nums[n + i];
            position++;
        }
        // There are n pairs and i am placing two elements(one pair) for each iteration
        // That's why loop n times(n pairs getting placed)
        return result;
    }
};

/*

TC -> O(n) | SC -> O(n)

*/

