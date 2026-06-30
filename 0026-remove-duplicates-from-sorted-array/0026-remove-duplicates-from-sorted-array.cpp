class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // index 0 se start karna hai (because nums[0] is the first unique element, already placed correctly)
        for(int j = 1; j < nums.size(); j++){ // agla element jo same na ho wo dhoondhna hai, isliye j = 1 se array ke end tak traverse karna hai(Kyunki j = 0 wala to already unique hai na)
            if(nums[i] != nums[j]){ 
                i++;
                nums[i] = nums[j]; // agar mil gaya, to jitne same the(apne current wale element se), unko 1 position se aage shift karte hue us unique element ko le aana hai, apne current wale element ke just baad(isliye i++)
            }// phir loop chalne laga next element ke liye, aur ab us next element se different element dhoodhna hai
            // i ko constant rakhna hai tab tak jab tak koi different element na mil jaye, jaise hi mila koi different element, use aage le aana hai i = i + 1 ki jagah pe
        }
        return i + 1; // unique elements kitne hue? -> 1 pehla tha hi, aur i elements aur jo mile(jab jab do elements different hue), aage badhte hue
                      // Or think like this, i is the index of last unique element
                      // so total unique elements -> index + 1
    }
};

/*

Time Complexity -> O(n)
Space Complexity -> O(1)

*/

// This pattern is known as SLOW-FAST POINTER

/*

Because array is sorted -> duplicates are together

i pointer -> last position where unique element has been placed
j pointer -> Scans the array from left to right 

naya element mil gaya agar(nums[j] != nums[i])
to i++ karke nums[j] wahan laga den

*/