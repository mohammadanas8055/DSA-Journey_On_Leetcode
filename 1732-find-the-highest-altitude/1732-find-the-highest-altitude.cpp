class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int add = 0;
        int maxHeight= 0;
        for(int i = 0; i < gain.size(); i++){
            add = add + gain[i];
            maxHeight = max(maxHeight, add);
        }
        return maxHeight;
    }
};