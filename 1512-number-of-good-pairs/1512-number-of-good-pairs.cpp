class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs = 0;
        int arr[101] = {0};
        int frequency = 0;
        for(int i = 0; i < nums.size(); i++){
            pairs = pairs + arr[nums[i]];
            arr[nums[i]]++;
        }
        return pairs;
    }
};

/*

Stand on a number and see how many times the same number appeared BEFORE that position

*/