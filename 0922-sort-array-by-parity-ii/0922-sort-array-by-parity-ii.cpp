/*

Instead of creating a new array (SC -> O(n)), we can do it in-place using swaps

*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0;
        int odd = 1;
        // even pointer hamesha even indices(0,2,4...) par hi chalega
        // odd pointer hamesha odd indices91,3,5...) par hi chalega

        while(even <= nums.size() - 1 && odd <= nums.size() - 1){
// or   while(even < n && odd < n)
            // Jab tak dono pointers valid hain, tab tak check karenge
            // && zaroori hai kyunki agar ek bhi out of bounds chala gaye
            // to usko access karna crash karwa dega

            if(nums[even] % 2 == 0){
                // Agar even index par already even number hai
                // to wo corrct jagah par hai. Usme koi problem nahi

                even += 2;
                // Next even index par move kar jao

                continue;
            }
            if(nums[odd] % 2 != 0){
                // Agar odd index par already odd number hai
                // to wo bhi correct jagah par hai

                odd += 2;
                // Next odd index par move kar jao

                continue;
            }

            // yahan code tabhi pahunchega jab:
            // 1. nums[even] odd number ho gaya(Galat jagah)
            // 2. nums[odd] even number ho gaya(Galat jagah)

            swap(nums[odd], nums[even]);
            // DOno misplaced elements ko swap kar diya
            // Ab dono apni correct parity position par aa gaye

            odd += 2;
            even += 2;
            // Swap ke baad dono correct ho chuke hain, to aage badh jao
        }
        return nums;
        // In-place modified array return kar di
    }
};

/*

At even index 0,2,4.., we care only if element there is odd, kyunki agar even hai to pehle hi correct hai
Similarly at odd index, only care if element is even
So even pointer ko aage badhao jab tak usko odd element na mil jaye
odd pointer ko aage badhao jab tak usko even element na mil jaye
jab dono pointers galat elements par ruk jayen -> un dono ko swap kar do
repeat until any pointer goes out of bounds(koi sa bhi ek)

This works because array is guaranteed to have half even numbers, half odd numbers
So whenver there is a misplaced odd number at an even index, there MUST be a misplaced even number at an odd index somewhere
We just find them and swap them

> Why && is correct and || is dangerous 
If even goes out of bounds(eg. even > n- 1), but odd is still inside -> then loop will continue -> out of bounds/segmentation fault
Why && works:
We only swap when BOTH pointers have found a misplaced element
Agar ek pointer scan karke khatam ho gaya, yaani saare elements of its type are correctly placed. And because the array has exactly half even and half odd numbers, if all evens are correctly placed, all odds MUST also be correctly placed
So as soon as ANY ONE pointer goes out of bounds, the whole array is sorted by parity. We can safely stop

TC -> O(n) | SC -> O(1) extra space

*/