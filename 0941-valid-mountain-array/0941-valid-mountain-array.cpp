class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;
        int n = arr.size();

        // Phase 1: Strictly increasing part
        while(i + 1 < n && arr[i + 1] > arr[i]){ // out-of-bound hone ke risk se bachne ke liye i + 1 < size of the array 
            i++;
        }
        // i is the peak now
        // But kya valid peak hai?

        if(i == 0 || i == n - 1){
            return false; // Peak cannot be first or last element
        }

        // Phase 2: Strictly decreasing part
        while(i + 1 < n && arr[i + 1] < arr[i]){
            i++;
        }
        return i == n - 1;
    }
};

// class Solution {
// public:
//     bool validMountainArray(vector<int>& arr) {
//         if(arr.size() < 3){
//             return 0;
//         }
//         int i = 0;
//         if(arr[0] > arr[1]){
//             return 0;
//         }
//         for(int j = 0; j < arr.size() - 1; j++){
//             if(arr[j] < arr[j + 1]){
//                 i++;
//             }
//         }
//         if(i == arr.size() - 1){
//             return 0;
//         }
//         for(int k = i; k < arr.size() - 1; k++){
//             if(arr[k + 1] >= arr[k]){
//                 return 0;
//             }
//         }
//         return 1;
//     }
// };

/*

This is optimal, TC -> O(n) and SC -> O(1)
Implementation is indirect

*/

/*

Main issue:
i is counting how many increasing adjacent pairs exist in the whole array, but i should mean "index of the peak"
match to kar raha hai, count = peak index
but cleaner way is not to count increases

Cleaner way -> Walk Upward Until You Cannot Walk Upward Anymoe

Phase 1: climb up strictly
Phase 2: climb down strictly
So use one pointer

Step 1: Walk up

while(i + 1 < n && arr[i] < arr[i + 1]){
    i++;
}
This keeps moving while the array is increasing
When this stops, i is at the possible peak

Step 2: Peak shouldn't be first or last

Therefore
if(i == 0 || i == n - 1){
    return false;
}

Step 3: Walk down

while(i + 1 < n && arr[i] > arr[i + 1]){
    i++;
}
Now move while decreasing. At the end, if you reached the last index, VALID MOUNTAIN

return i == n - 1;

i means "current position while walking through mountain"
and not "number of increasing pairs"

walk up → check peak → walk down → see if reached end

So still TC -> O(n) and SC -> O(1)

Pattern: Phase walking
First strictly increasing phase
Then strictly decreasing phase
Peak must not be first or last

Useful when array/string has phases

*/