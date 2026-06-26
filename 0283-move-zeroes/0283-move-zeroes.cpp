class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
    }
};

/*

O(n) Time Complexity and O(1) Space complexity

Non-zeros remain relative order, j starts from 0 so to ensure if 1st element is also non-zero

Slow-pointer -> next non-zero placement
Fast-pointr -> scans non-zeros
jab non-zero ko laga diya, to i++ kar diya

piche se nahi shuru kiya nahi to relative order of non-zeros kharab ho jata

*/
