// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int actualSum = 0;
//         int n = nums.size();
//         // n elements hain, aur range [0,n] hai
//         // matlab total range me n + 1 numbers hain, par hame n diye gaye hain

//         // Step 1: Array me jo numbers maujood hain unka sum nikaalo
//         for(int i = 0; i < n; i++){
//             actualSum += nums[i];
//         }

//         // Step 2: [0,n] range ka ideal/expected sum kya hona chahiye
//         // Ham maths formula n * (n + 1) / 2 bhi use kar sakte hain
//         // ya simple loop se nikaal sakte hain
//         int expectedSum = 0;
//         for(int i = 0; i <= n; i++){
//             expectedSum += i;
//         }

//         // Expected Sum aur Actual Sum ka difference hi wahi number hai jo missing hai
//         // Kyunki baaki saare numbers dono sums me common hain aur cancel out ho jayenge
//         return expectedSum - actualSum;
//     }
// };

/*

Sorting takes O(nlogn)

O(n) solution:
n distinct numbers taken from [0,n] -> exactly ONE number is missing
bas total me se given sum ko minus kar do, missing number aa jayega

intendedSum = n * (n + 1) / 2; direct formula

TC -> O(n) + O(n) = O(n) | SC -> O(1)

XOR method
This avoids potential overflow if n is very large(10^6)
XOR -> never overflow kyunki bits pe kaam karta hai
Saare [0,n] ko XOR karo, aur phir nums ke saare elements ko, saare same elements cut ho jayenge(a^a = 0) aur sirf missing number bach jayega

*/

class Solution{
public:
    int missingNumber(vector<int>& nums){
        int missingNumber = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            missingNumber = missingNumber ^ i ^ nums[i];
        }
        missingNumber = missingNumber ^ n;
        return missingNumber;
    }
};