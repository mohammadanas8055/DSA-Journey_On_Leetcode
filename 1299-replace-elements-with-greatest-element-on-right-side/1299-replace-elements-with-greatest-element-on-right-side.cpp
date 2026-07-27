// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& arr) {
//         for(int i = 0; i < arr.size() - 1; i++){
//             int maximum = arr[i + 1];
//             for(int i = i + 1; i < arr.size(); i++){
//                 if(arr[i] > maximum){
//                     maximum = arr[i];
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
        int maximumOnRight = -1;
        // maximumOnRight ab tak right side me dekha gaya sabse bada element store karega
        // Initially -1 isliye, kyunki last element ke right me kuch nahi hota
        // aur question ke according last element ko -1 se replace karna hai

        for(int i = arr.size() - 1; i >= 0; i--){
            int temp = arr[i];
            // save current original value
            // kyunki arr[i] ko ab overwrite karne wale hain

            arr[i] = maximumOnRight; 
            // Current element ko uske right side ke greatest se replace kar diya

            if(temp > maximumOnRight){
                maximumOnRight = temp;
            }
            // Ab original current value ko future right-side maximum ke liye consider karna hoga
            // Kyunki next iteration me ye current element bhi kisi aur ke right side me aayega

            // This order is the key
        }
        return arr;
        // in-place modified array return kar di
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