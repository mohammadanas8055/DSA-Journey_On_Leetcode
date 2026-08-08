class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        // totalSum me pure array ka sum stor karenge
        // Isse har index par right side ka sum efficiently nikaal payenge
        // bina baar-baar pura array dobara add kiye

        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }
        int leftSum = 0;
        // leftSum hamesha current index ke left side ke elements ka sum rakhega
        // Initially current index 0 hoga, aur uske left me kuch nahi hota
        // isliye start 0 se kiya

        for(int i = 0; i < nums.size(); i++){
            int rightSum = totalSum - leftSum - nums[i];
            // totalSum me:
            // [left side] + [current element] + [right side]

            // To sirf right side nikaalne ke liye:
            // totalSum me se leftSum hata do
            // aur current element nums[i] bhi hata do
            
            // jo bachega wahi right side ka sum hoga
             
            if(leftSum == rightSum){
                return i;
                // Agar left aur right sum equal hain
                // to i valid middle index hai
            }
            leftSum += nums[i];
            // Current index ka element ab next iteration ke liye left side ka part ban jayega
            // Isliye check ke BAAD add kar rahe hain, pehle nahi 

            // Agar is line ko if se pehle likhte 
            // to current elementgalti se left side me count ho jaata
        }
        return -1;
        // Agar kisi bhi index par left aur right equal nahi hue 
        // to middle index exist nahi karta
    }
};

/*

For middle index i, we want:
sum of elements before i == sum of elements after i

totalSum contains: left side, current element, right side
So to isolate right side only, we remove 1. leftSum 2. nums[i]

Order is very important: leftSum update must happen after the check because leftSum should only contain elements before i

TC -> O(n) | SC -> O(1)

*/