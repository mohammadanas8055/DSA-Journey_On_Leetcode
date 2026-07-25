// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size(); // array ka total size store kar liya

//         vector<int> ans(n); // new array banayi jisme rotated answer store karenge
//                             // Isliye is approach ki extra space O(n) hai

//         int position = 0; // position batayega ans me next element kis index par fill karna hai

//         k = k % n; // what if k > n
//                    // n - k would be invalid
//                    // so k % n 
//                    // taaki remainder mil jaye(agar n se bada ho to, n baar rotate karoge to wahi array dobara mil jayega), to remainder baar hi rotate karna padega
//                    // rotating by n positions changes nothing(sirf effective rotation count rakho)

//         for(int i = n - k; i < n; i++){ // Last k element come to front

//             ans[position] = nums[i];
//             position++;
//             // Last k elements ko pehle copy kar rahe hain
//             // kyunki right rotation me last ke elements front par aa jate hain
//         }        
//         for(int i = 0; i < n - k; i++){ // After moving last k elements, we need to copy first n - k elements(and not first k elements) 

//             ans[position] = nums[i];
//             position++;
//             // Ab bache hue first n - k element ko copy kar rahe hain
//             // ye last k elements k baad answer me aayenge
//         }
//         nums = ans;
//         // final rotated array ko original nums me copy kar diya
//     }
// };

// /*

// This approach consists of:
// . Copy last k element
// . Copy first n - k elements

// TC -> O(n) | SC -> O(n)

// We can try for in-place 
// Can I convert A + B into B + A inside the same array
// A = first n - k elements
// B = last k elements
// eg. [1, 2, 3, 4 | 5, 6, 7] -> [5, 6, 7 | 1, 2, 3, 4]

// > Can reversing help me rearrange blocks?
// -> First reverse the array [7, 6, 5, 4, 3, 2, 1]

// Now first k elements are reverse version of B
// Remaining n - k elements are reversed version of A (i.e. reverse(B) + reverse(A))

// -> So reverse first k elements [5, 6, 7]
// -> Reverse remaining n - k elements [1, 2, 3, 4]

// */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // total number of elements in the array

        k = k % n; // Agar k, n se bada hai to full rotations useless hain
                   // Example:
                   // n = 7, k = 10
                   // rotate by 10 is same as rotate by 3
                   // Isliye effective rotation count rakha

        int i = 0;
        int j = nums.size() - 1;
        // Pehle pura array reverse karenge
        // Shortcut: reverse(nums.begin(), nums.end());

        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        // Right ortation me last k elements front me aane chahiye 
        // Pura reverse karne ke baad wo elements front me aa jate hain
        // but ulta order me

        int i2 = 0; 
        int j2 = k - 1;
        // Ab first k elements reverse karenge
        // ye wahi part hai jo original array ke last k elements the
        // Shortcut: reverse(nums.begin(), nums.begin() + k);

        while(i2 < j2){
            swap(nums[i2], nums[j2]);
            i2++;
            j2--;
        }
        // Ab rotated array ka front part sahi order me aa gaya

        int i3 = k; 
        int j3 = n - 1;
        // Ab remaining n - k elements reverse karenge
        // Ye original array ke first n - k elements the, jo abhi ulta pade hain
        // Shortcut: reverse(num.begin() + k, nums.end());

        while(i3 < j3){
            swap(nums[i3], nums[j3]);
            i3++;
            j3--;
        }
        // Final rotated array mil gayi
    }
};

/*

A = first n - k elements
B = last k elements 
Right rotation by k means: A + B -> B + A

-> reverse whole array (A + B -> reverse(B) + reverse(A))
-> Reverse first k elements (reverse(B) -> B)
-> Reverse remaining n - k elements (reverse(A) -> A)
-> Final (B + A)

Shuru me k elements hain
unke indices 0 to k - 1 honge
Fir n - k elements hain
total size = n
first part took k positions
so rest begins from index k and goes till n - 1

TC -> O(n) (O(n + k + (n - k)) = O(2n) = O(n)) | SC -> O(1)

*/