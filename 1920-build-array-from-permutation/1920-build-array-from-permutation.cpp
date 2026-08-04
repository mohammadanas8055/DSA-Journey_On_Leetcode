class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        // answer array alag banani pad rahi hai
        // kyunki hame original nums ki values safe rakhni hain while computing answers

        // Agar ham nums ko hi directly overwrite karne lagen
        // to future indices ke liye original permutation values lose ho sakti hain

        for(int i = 0; i < nums.size(); i++){
            ans[i] = nums[nums[i]]; 
            // ye line tabhi safe hai kyunki nums permutation hai
            // yani uski har value valid index range[0, n - 1] me hoti hai
        }
        return ans;
        // complete constructed permutation array return kar di
    }
};

/*

TC -> O(n) | SC -> O(n)

O(1) SC solution involves encoding 2 values in 1 cell
Each cell stoes BOTH: its old value, its new value at the same time
Using this encoding:
nums[i] = nums[i] + n * (nums[nums[i]] % n), where n = nums.size()

# Why % n here
At index i, you want to calculate the new value
The new value is supposed to be: the ORIGINAL value sitting at index nums[i] 
Now, we are processing from i = 0 to n - 1
Suppose i = 3 -> We might need 0, 1 or 2 
But you already encoded(modified) the values at indices 0, 1 and 2 during the earlier stpes of the loop
if we just write nums[nums[i]], we will get the encoded/modified huge number that we placed there earlier, not the clean original number we actually need
eg. [1,2,0] (n = 3)
i = 0
nums[0] = 1
target index = 1
value at target = nums[1] = 2
encode: nums[0] = 1 + 3 * 2 = 7
now array is [7,2,0]

i = 1
original value: nums[1] = 2
target index = 2
value at target = nums[2] = 0
encode: nums[1] = 2 + 3 * 0 = 2
now array is [7,2,0]

i = 2
nums[2] = 0
index = 0
value at target = 7 (nums[0] is now 7)
If we dont use % n, our NEW value becomes 7
encode: nums[2] = 0 + 3 * 7 = 21(Wrong)

HOW % n fixes it
We need original value at index 0
currently nums[0] = 7
How did we build 7 
7 = oldValue + n * newValue
7 = 1 + 3 * 2
To strip the n * newValue part and get the OldValue(which is 1), we just take the modulo n
7 % 3 = 1 
So we tak nums[nums[i]] % n
now encoding becomes: nums[2] = 0 + 3 * 1 = 3(Correct)

So correct encoding hai
[1,2,0] -> [7,2,3]
then getting new Values
dividing by 3
[2,0,1] correct answer

So we need % n because the element we are looking at might have already been encoded in a previous step, and % n safely strips away the encoded part to give you the clean, original value

old value can be recovered by: nums[i] % n
new value can be recovered by: nums[i] / n

Why % n gives old value? 
because encoding adds: 
n * something
and since all original values are in range [0, n - 1]:
(original + n * something) % n = original
Because n * something is perfectly divisible by n


Why / n gives new value?
because
(original + n * newValue) / n = newValue
Since original < n, integer division drops it

*/

// class Solution{
// public:
//     vector<int> buildArray(vector<int>& nums){
//         int n = nums.size();
//         // n = total element
//         // sab values [0, n - 1] range me hain kyunki permutation hai

//         // Step 1: har cell me 2 values encode karo
//         // Formula: nums[i] = oldValue + n * newValue

//         // Baad me
//         // oldValue recover karne ke liye: nums[i] % n
//         // newValue recover karne ke liye: nums[i] / n
//         for(int i = 0; i < n; i++){
//             int oldValue = nums[i];
//             // current cell ki original value

//             int newValue = nums[nums[i]] % n;
//             // nums[nums[i]] already encoded ho sakta hai
//             // isliye % n use karke uski ORIGINAL value recover ki

//             // ye line isliye safe hai kyunki
//             // (original + n * something) % n = original
//             // kyunki original hamesha [0,n - 1] range me hai

//             nums[i] = oldValue + n * newValue;
//             // Ab ek hi cell me dono values packed hain
//             // oldValuerecoverable via % n
//             // newValue recoverable via / n
//         }

//         // Step 2: Har cell me sirf newValue extract karo
//         for(int i = 0; i < n; i++){
//             nums[i] = nums[i] / n;
//             // Integer division se newValue mil jaata hai
//             // kyunki oldValue < n hai, wo division me automatically drop ho jata hai
//         }
//         return nums;
//         // Ab nums in-placer modified ho chuka hai
//     }
// };

/*

TC -> O(2n) -> O(n) | SC -> O(1)

*/