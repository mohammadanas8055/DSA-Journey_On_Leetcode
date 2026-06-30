class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

/*

i = position where next valid element should be placed.
j scans every element.

If current element should stay, place it at index i.
Then move i forward.
So after loop, first i elements are the valid answer.

Time Complexity: O(n) -> Single pass.
Space Complexity: O(1) -> In-place.

This is the optimal solution

*/