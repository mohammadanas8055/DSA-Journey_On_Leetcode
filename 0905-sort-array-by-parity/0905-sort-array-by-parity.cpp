class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] % 2 == 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
        return nums;
    }
};

/*

agar 2 se divisible hoga, to swap kar dena hai
shuru me aa jayenge saar odd

TC -> O(n) | SC -> O(1)

Pattern: slow-fast partition
- i = next position for even number -> It is not just a pointer -> From index 0 to i - 1, all numbers are already correctly placed as even
- j = scanner

*/

/*

Another Approach:Two Pointer from Opposite End

Left side should contain even numbers.
Right side should contain odd numbers.
So if left has odd and right has even, swap them

If nums[i] is even, it is already on correct side → move i++
If nums[j] is odd, it is already on correct side → move j--
If nums[i] is odd and nums[j] is even, both are on wrong sides → swap them

while(i < j){
    if(nums[i] % 2 == 0){
        i++;
    } 
    else if(nums[j] % 2 != 0){
        j--;    
    }   
    else{       // yani left me odd hai, right me even hai, to swap kar den
        swap;
        i++;
        j--;
    }
}

This version is useful when 
Put one type on left, another type on right

*/