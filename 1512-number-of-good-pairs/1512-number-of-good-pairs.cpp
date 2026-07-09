class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs = 0;
        int frequency[101] = {0};
        for(int i = 0; i < nums.size(); i++){
            pairs = pairs + frequency[nums[i]];
            frequency[nums[i]]++;
        }
        return pairs;
    }
};

/*

Stand on a number and see how many times the same number appeared BEFORE that position

arr[x] stores: how many times number x has appeared before current index
Inputs were 1 to 100 , so made 101 boxes(0 to 100 indexed) for counting how many times a number has appeared before

If current number appeared before k times, then k new pairs
Phir current number ka count badha diya for fiture elements

TC -> O(n) | SC -> O(1) because freq[101] is fixed size

Pattern:
frequency count with fixed-size array

Here we used frequency while scanning, instead of checking at the end(in case of Valid Anagram)

*/