class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> maxCandies(candies.size(), true);
        for(int i = 0; i < candies.size(); i++){
            int temp = candies[i] + extraCandies;
            for(int j = 0; j < candies.size(); j++){
                if(temp < candies[j]){
                    maxCandies[i] = false;
                }
            }
        }
        return maxCandies;
    }
};