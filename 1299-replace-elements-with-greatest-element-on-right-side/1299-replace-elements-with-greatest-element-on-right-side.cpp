// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& arr) {
//         for(int i = 0; i < arr.size() - 1; i++){
//             int maximum = arr[i + 1];
//             for(int j = i + 1; j < arr.size(); j++){
//                 if(arr[j] > maximum){
//                     maximum = arr[j];
//                 }
//             }
//             arr[i] = maximum;
//         }
//         arr[arr.size() - 1] = -1;
//         return arr;
//     }
// };

// TC -> O(n^2) | SC -> O(1)

// Maybe we should start from the end, so that right side is checked of the maximum values and the array can be modified in-place, using one pointer

class Solution{
public:
    vector<int> replaceElements(vector<int>& arr){
        int maxRight = -1;
        for(int j = arr.size() - 1; j >= 0; j--){
            int temp = arr[j]; // save old current value before overwriting 
            arr[j] = maxRight; // Replace current element with greatest value seem on its right
            if(temp > maxRight){
                maxRight = temp;
            } // now old value becomes part of the "right side" for future elements on the left
        }
        return arr;
    }
};

/*

For each element, we needed "greatest element on its right side"
agar left se right jayenge to aage ke elements nahi pata, to sabko scan karna pad raha hai
But agar right to left aayenge, the "RIGHT SIDE" has already been seen

Aakhri element hamesha -1 rehna hai to maximum ko -1 se initialise karwa diya
maximum = maximum value among elements to the right of current index

TC -> O(n) | SC -> O(1)

. Pattern: reverse traversal + track best value on right
When answer for index i depends on elements to its right,
scan from right to left.

This pattern will come back in problems involving:

next greater element,
suffix maximum,
stock/span-like ideas,
right-side dependent replacement.

*/