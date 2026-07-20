class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0; // totalSum me poore array ka sum store karenge
                          // taaki har index par right side ka sum efficiently nikaal saken

        for(int i = 0; i < nums.size(); i++){
            totalSum = totalSum + nums[i];
        } // O(n) for total sum

        int leftSum = 0; // leftSum hamesha current index ke left side ke elements ka sum rahega

        int rightSum = 0; // rightSum current index ke right side ka sum hoga

        for(int i = 0; i < nums.size(); i++){
            rightSum = totalSum - nums[i] - leftSum; // totalSum me pura array included hai
                                                     // pivot index i check karne ke liye:
                                                     // - leftSum hata do (left side remove ho gayi)
                                                     // - nums[i] hata do (pivot khud left ya right me count nahi hota)
                                                     // jo bachega wahi right side ka sum hoga

            if(leftSum == rightSum){ // Agar left aur right sum equal hain
                                     // to i valid pivot index hai
                return i;
            }
            leftSum = leftSum + nums[i]; // Current index ko check karne ke baad hi nums[i] ko leftSum me add karenge
                                         // kyunki next iteration me ye next index ke left side ka part ban jayega
        } // O(n) for pivot check

        return -1; // Agar kisi bhi index par left aur right equal nahi hue
                   // to pivot index exist nahi karta

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

TC -> O(n) | SC -> O(1)

Pattern: prefix/running sum
totalSum = sum of whole array
leftSum = sum before current index 
rightSum = totalSum - leftSum - nums[i]
Check first, then add nums[i] to leftSum

*/