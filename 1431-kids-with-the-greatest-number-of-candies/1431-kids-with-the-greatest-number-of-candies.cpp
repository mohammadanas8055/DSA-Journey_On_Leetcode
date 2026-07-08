// class Solution {
// public:
//     vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
//         vector<bool> maxCandies(candies.size(), true);
//         for(int i = 0; i < candies.size(); i++){
//             int temp = candies[i] + extraCandies;
//             for(int j = 0; j < candies.size(); j++){
//                 if(temp < candies[j]){
//                     maxCandies[i] = false;
//                 }
//             }
//         }
//         return maxCandies;
//     }
// };

// This is O(n^2) TC
// For every kid, we are searching whether he has more candies than the maximum one
// Instead, find the maximum one and then compare each kid with that maximum value

class Solution{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
        int maximum = candies[0];
        for(int i = 1; i < candies.size(); i++){
            if(candies[i] > maximum){
                maximum = candies[i];
            }
        }
        vector<bool> result;
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maximum){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};

// TC -> O(n) + O(n) = O(n) | SC -> O(n)