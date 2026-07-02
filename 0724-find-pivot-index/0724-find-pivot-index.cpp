class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum = totalSum + nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum){
                return i;
            }
            else{
                leftSum = leftSum + nums[i];
            }
        }
        return -1;
    }
};

/*

i++ or j-- or both belongs to problems like:
sorted array pair, reverse string, merge sorted array, sort by parity, squares of sorted array

Here there aren't two pointers moving toward each other. This problem is like:
* Stand at each index and ask: Is the sum on my left equal to the sum on my right?
That's the required index
Only one pointer moving from left to right

so first find totalSum , then leftSum ko 0 maan ke , har index pe, rightSum nikaal lenge(total - left - number at index i itself)
agar equal hue, left aur right sum , to wahi index return kar dena hai
agar nahi hue, to index ko badhana hi hai, aur us number ko leftSum me store bhi karna hai, jisse aage badhe hain
AND this should be done AFTER checking, because nums[i] itself should not be included in leftSum
It becomes left side only for the next index

Pattern: prefix/running sum
totalSum = sum of whole array
leftSum = sum before current index 
rightSum = totalSum - leftSum - nums[i]
Check first, then add nums[i] to leftSum

*/