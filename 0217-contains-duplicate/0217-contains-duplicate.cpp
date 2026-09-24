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
        for(int i = 0; i < nums.size(); i++){
            if(ans.count(nums[i])){
                return true;
            }
            ans.insert(nums[i]);
        }
        return false;
    }
};