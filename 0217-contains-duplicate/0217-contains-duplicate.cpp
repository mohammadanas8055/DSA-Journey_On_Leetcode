// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         for(int i = 0; i < nums.size() - 1; i++){ 
//             for(int j = i + 1; j < nums.size(); j++){
//                 if(nums[i] == nums[j]){
//                     return true;
//                 }   
//             }
//         }
//         return false;
//     }
// };

// // This has O(n^2) Time complexity 

// class Solution{
// public:
//     bool containsDuplicate(vector<int>& nums){
//         sort(nums.begin(), nums.end()); 
//         for(int i = 0; i < nums.size() - 1; i++){
//             if(nums[i] == nums[i + 1]){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// This has time complexity O(nlogn) 

/// DUPLICATE DETECTION PATTERNS

// Brute Force: O(n²) — DON'T submit unless desperate
//   for i: for j: if nums[i]==nums[j] → duplicate

// Sort + Adjacent: O(n log n) — use without STL
//   sort, then check nums[i]==nums[i+1]

// Hash Set: O(n) — best, but needs STL
//   unordered_set<int>; check if seen before adding

// RULE: Always ask "can I do better than O(n²)?" before submitting

class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
        unordered_set<int> ans;
        // unordered_set use kar rahe hain kyunki:
        // 1. Hame sirf element ki PRESENCE(kya ye pehle dikha hai?) check karni hai, frequency count nahi chahiye
        // 2. unordered_set Hash Table par tikta hai, isliye lookup .find() / .count() aur insertion .insert() dono average O(1) time me hote hain
        // 3. Simple set(Red-Black tree) O(logN) leta, jabki hame sorted order ki zaroorat nahi
        // Isliye unordered_sett O(N) overall time ke liye strictly better hai

        for(int i = 0; i < nums.size(); i++){
            // Array ko ek single pass me scan karenge(Left to Right)
            
            if(ans.find(nums[i]) != ans.end()){
                // ans.find(x) iterator return karta hai:
                // - Agar element 'x' set me MAUJOOD hai -> iterator points to that element (!= ans.end())
                // - Agar element 'x' set me NAHI hai -> iterator points to ans.end()

                // Reason for check BEFORE insert:
                // Current element ko set me daalne se PEHLE check karna zaroori hai
                // Agar pehle check karenge aur wo pehle se set me hai, iska matlab duplicate mil gaya
                // Directly return true kar do

                return true;
            }
            ans.insert(nums[i]);
            // Agar current element pehle nahi dikha tha
            // to ise 'ans' set me daal do taaki aage aane wale duplicate elements ise pehchaan saken 
        }
        return false;
        // Agar pura loop bina kisi hit ke khatam ho gaya
        // iska matlab array me saare element DISTICT/UNIQUE hain
    }
};

/*

Same logic:
for(int i:nums){
    if(ans.count(i)) return true; // .count(x) returns 1 if present, 0 is absent
    ans.insert(i);
}
return false;

TC -> O(N) average (Worst case O(n^2) theoretical, jab Hash Collisions extreme hon) | SC -> O(N)

*/