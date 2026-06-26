class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0; 
        int j = nums.size() - 1;
        int pos = nums.size() - 1;
        while(i <= j){
            int leftSquare = nums[i] * nums[i];
            int rightSquare = nums[j] * nums[j];
            if(leftSquare > rightSquare){
                result[pos] = leftSquare;
                i++;
            }
            else{
                result[pos] = rightSquare;
                j--;
            }
            pos--;
        }
        return result;
    }
};

/*

Pattern: Two-pointer from opposite ends with auxiliary array
This pattern appears in:

Squares of Sorted Array ✅ 
Merge Two Sorted Arrays
Container with Most Water (variation)
Many sorted array merge problems

new array banayenge -> Space Complexity O(n)
but time complexity is reduced from O(nlogn) to O(n) (By sorting method) -> (Squaring first, then sorting)
but we needed to use the fact that the array IS ALREADY sorted 
that's why we used two-pointers from opposite ends, because largest values will be at either ends(after squaring)
so square the extreme elements, compare them, then store them, from BACK to FORTH in a new array
move the pointers and the position (in the new array) accordingly

*/
